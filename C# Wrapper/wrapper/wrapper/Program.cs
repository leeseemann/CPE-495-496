/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

Program.cs - C# wrapper which utilizes a DLL to run the C++ source code of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee 			12/28/15		file created, imported C++ DLL
Lee             1/31/15         added code to retrive Kinect depth info and pass it to DLL

--------------------------------------------------------------------------------
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Kinect;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace wrapper
{
   public class Program
    {
        [STAThread]
        [DllImport("A:\\School\\Spring 2016\\CPE 496\\Code\\CPE_Senior_Design\\DLL\\x64\\Debug\\Steelcase_Answer_Verification_DLL.dll")]
        public static extern void Steelcase_Answer_Verification(short[] depth_data);
        static KinectSensor sensor; 
        static short[] depth_data; // array to hold the depth info provided by Kinect

        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            //short[] depth_data = new short[3] { 0, 1, 2 };
            retrieveKinectDepth();
            Steelcase_Answer_Verification(depth_data); // pass the depth data to the C++ DLL
        }

        static void retrieveKinectDepth()
        {
            // initialize and start Kinect sensor
            sensor = KinectSensor.KinectSensors[0];
            sensor.DepthStream.Enable(DepthImageFormat.Resolution640x480Fps30);
            sensor.DepthFrameReady += depthFrameReady; // event handler that executes when a frame is ready
            sensor.Start();
        }

        static void depthFrameReady(object sender, DepthImageFrameReadyEventArgs depth)
        {
            DepthImageFrame frame = depth.OpenDepthImageFrame();
            if(frame != null)
            {
                sensor.Stop();
                depth_data = new short[frame.PixelDataLength];
                frame.CopyPixelDataTo(depth_data);

                // for example, find the middle pixel in the frame
                int x = frame.Width / 2;
                int y = frame.Height / 2;
                int d = (ushort)depth_data[x + y * frame.Width];
                d = d >> 3;

                // d now contains the distance of the pixel from the Kinect in mm
            }
        }
    }
}
