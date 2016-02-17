/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

Program.cs - C# wrapper which utilizes a DLL to run the C++ source code of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee 			12/28/15		file created, imported C++ DLL
Lee             1/31/16         added code to pass Kinect depth info to DLL
Lee             2/2/16          added code to retrieve depth data from Kinect
Lee             2/17/16         added code to average multiple frames of Kinect 
                                depth data together before sending it to DLL
--------------------------------------------------------------------------------
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Kinect;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Windows;
using System.Diagnostics;
using System.Threading;

namespace wrapper
{
   public class Answer
    {
        // import the C++ DLL 
        [STAThread]
        [DllImport("C:\\Users\\Lee Seemann\\Documents\\GitHub\\CPE_Senior_Design\\DLL\\x64\\Debug\\Steelcase_Answer_Verification_DLL.dll")]

        public static extern void Steelcase_Answer_Verification(short[] depth_data); // the function that will call the C++ DLL

        // Variable declarations
        public const short NUM_FRAMES = 2; // number of frames to average together before sending depth data to DLL
        public int frame_count = 0; // track the number of frames that have been retrieved for the current order
        public List<short[]> depth_frames = new List<short[]>(); // list to hold multiple frames of depth data until they can be averaged
        KinectSensor sensor; // the Kinect sensor
        public short[] depth_data; // array to hold the depth info provided by the Kinect

        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            Answer instance = new Answer();
            instance.retrieveKinectDepth(); // retrieve the depth data
        }

        void retrieveKinectDepth()
        {
            // initialize and start the Kinect sensor
            sensor = KinectSensor.KinectSensors[0];
            sensor.DepthStream.Enable(DepthImageFormat.Resolution640x480Fps30);
            sensor.DepthFrameReady += depthFrameReady; // event handler that executes when a frame is ready
            // start the sensor, and abort if there is an issue
            try
            {
                sensor.Start();
            }
            catch(InvalidOperationException)
            {
                sensor = null;
                Console.WriteLine("ERROR: No Kinect Sensor Found");
            }

            Thread.Sleep(10);  // stop the program long enough for a frame to become available from the Kinect, temporary fix
            while (frame_count < NUM_FRAMES) ; // wait until a sufficient number of frames have been retrieved

            // don't forget to shift the bits of the depth data, this is not currently done before sending it to the DLL
            Steelcase_Answer_Verification(depth_data); // pass the averaged depth data to the C++ DLL
        }

        void depthFrameReady(object sender, DepthImageFrameReadyEventArgs e)
        {
            if (frame_count < NUM_FRAMES)
            {
                using (DepthImageFrame frame = e.OpenDepthImageFrame()) // retrieve the frame
                {
                    if (frame != null) // check for an invalid frame
                    {
                        sensor.Stop(); // temporarily disable the Kinect sensor
                        depth_data = new short[frame.PixelDataLength]; // allocate space to hold the depth data
                        frame.CopyPixelDataTo(depth_data); // copy the depth data 
                        depth_frames.Add(depth_data); // add the depth data to the list of frames   
                    }
                    frame_count++;
                  
                    if (frame_count == NUM_FRAMES - 1) // if we have all the frames we need
                    {
                        sensor.Stop();
                        depth_data = averageKinectDepth(depth_frames); // average the depth data from all the frames retrieved
                    }
                    sensor.Start();  // restart the sensor
                }
            }
        }

        short[] averageKinectDepth(List<short[]> depth_frames)
        {
            short[] average_depth = new short[depth_frames[0].Length]; // temp array to hold averaged depth data

            for(int i = 0; i < depth_frames[0].Length; i++) // initialize the array elements to 0
                average_depth[i] = 0;
   
            //average all data in depth_frames and return a single array
            for(int i = 0; i < depth_frames.Count; i++)
            {
                for (int j = 0; j < depth_frames[i].Length; j++)
                    average_depth[j] += depth_frames[i][j];
            }

            for (int k = 0; k < average_depth.Length; k++)
            {
                average_depth[k] = (short)(average_depth[k]/NUM_FRAMES);
            }

            return average_depth;
        }

        

     }

}
