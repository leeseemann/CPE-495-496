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
Lee             2/23/16         added code to retrieve color data from the Kinect
Lee             3/2/16          added code to save color data as a jpg/png file 
                                in order to access it from the c++ edge detection code
Lee             3/7/16          added code to display color image as part of debugging
Lee             3/8/16          added code to pass the color image file path to the C++ DLL for processing
Lee             3/10/16         added start/end buttons to the GUI to faciliate execution of the program
Lee             3/14/16         added code to process the success/failure of the verification
                                based on an int array received from the C++ DLL
Lee             3/23/16         added code to update the GUI based on the success/failure of the verification
--------------------------------------------------------------------------------
*/

using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Kinect;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Windows;
using System.Diagnostics;
using System.Threading;
using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Media.Imaging;
using System.Windows.Media;
using System.Windows.Controls;
using System.IO;


namespace wrapper
{
   public class Answer
    {
        // import the C++ DLL 
        [STAThread]
        [DllImport("C:\\Users\\Lee Seemann\\Documents\\GitHub\\CPE_Senior_Design\\DLL\\x64\\Debug\\Steelcase_Answer_Verification_DLL.dll")]
        public static extern IntPtr Steelcase_Answer_Verification(short[] depth_data); // the function that will call the C++ DLL


        // Variable declarations
        public const short NUM_FRAMES = 1; // number of depth frames to average together before sending depth data to DLL
        public int frame_count = 0; // tracks the number of frames that have been retrieved for the current order
        public List<short[]> depth_frames = new List<short[]>(); // list to hold multiple frames of depth data until they can be averaged
        KinectSensor sensor; // the Kinect sensor
        public short[] depth_data; // array to hold the depth info provided by the Kinect
        public byte[] color_data; // array to hold the color info provided by the Kinect
        bool color_retrieved = false; // used to determine if we have already retrieved color data for the current order
        public WriteableBitmap color_bitmap; // bitmap to hold the rgb data from the Kinect
        public string file_path; // path of the color image file
        IntPtr dll_ptr; // pointer used to retrieve results from the dll
        int[] results = new int[5]; // holds the ints that indicate the success/failure of each verification component
        public bool continue_verification = false;

        /// <summary>
        /// Main() creates an instance of the Answer class and kickstarts the verification process
        /// </summary>
        static void Main()
        {
            System.Windows.Forms.Application.EnableVisualStyles();
            System.Windows.Forms.Application.SetCompatibleTextRenderingDefault(false);
            Form1 GUI = new Form1();
           // System.Windows.Forms.Application.Run(GUI);
            GUI.ShowDialog();
            
            
            Answer instance = new Answer();
            instance.initKinectSensor();
            instance.retrieveKinectDepth();
            instance.retrieveKinectColor();

   //         System.Windows.Forms.Application.Run(GUI);
   //         instance.processResults(instance.results, GUI);

        }

       /* public void driver()
        {
           // while (continue_verification == false) ;
            
           // if(continue_verification == true)
           // {
                initKinectSensor();
                retrieveKinectDepth();
                retrieveKinectColor();
             //   continue_verification = false;
             //   driver();
            //}

        }*/

        /// <summary>
        /// initKinectSensor() connects to an available Kinect sensor
        /// </summary>
        public void initKinectSensor()
        {
            Console.WriteLine("Initializing Verification Software");
            foreach (var potential_Sensor in KinectSensor.KinectSensors) // are there any Kinect sensors available
            {
                if (potential_Sensor.Status == KinectStatus.Connected) // connect to the Kinect sensor
                {
                    sensor = potential_Sensor;
                    Console.WriteLine("Kinect Sensor Initialized");
                    break;
                }
            }
            if(sensor == null) // if there isn't a Kinect sensor to connect to
            {
                Console.WriteLine("ERROR: Kinect Not Initialized");
                System.Windows.Forms.Application.Exit();
            }
            //retrieveKinectDepth(sensor);
        }

        /// <summary>
        /// retrieveKinectData() initializes the Kinect sensor in order to begin the data retrieval process
        /// </summary>
        public void retrieveKinectDepth()
        {   
                // Initialize the depth sensor
                sensor.DepthStream.Enable(DepthImageFormat.Resolution640x480Fps30);
                sensor.DepthFrameReady += depthFrameReady; // event handler that executes when a frame is ready

                // start the sensor, and abort if there is an issue
                try
                {
                    sensor.Start();
                }
                catch (InvalidOperationException)
                {
                    sensor = null;
                    Console.WriteLine("ERROR: No Kinect Sensor Found");
                }
                Console.WriteLine("Kinect Sensor Retrieving Depth");
                Thread.Sleep(10);  // stop the program long enough for a frame to become available from the Kinect, temporary fix
                while (frame_count < NUM_FRAMES) ; // wait until a sufficient number of frames have been retrieved
                Console.WriteLine("Kinect Depth Data Successfully Retrieved");
             //   retrieveKinectColor();

        }

        /// <summary>
        /// retrieveKinectColor() initializes the Kinect sensor ColorStream and sets up the event handler colorFrameReady
        /// </summary>
        void retrieveKinectColor()
        {
            // Initialize the color sensor
            sensor.ColorStream.Enable(ColorImageFormat.RgbResolution640x480Fps30); // 1280 x 960 is also an option
            sensor.ColorFrameReady += colorFrameReady;

            // start the sensor, and abort if there is an issue
            try
            {
                sensor.Start();
            }
            catch (InvalidOperationException)
            {
                sensor = null;
                Console.WriteLine("ERROR: No Kinect Sensor Found");
            }
            
            while (color_retrieved == false) ;

            dll_ptr = Steelcase_Answer_Verification(depth_data); // pass the averaged depth data and color image to the C++ DLL
            Marshal.Copy(dll_ptr, results, 0, 5);
            //return results;
            //processResults(results);
        }

        /// <summary>
        /// depthFrameReady() is an event handler that executes each time a new frame of depth data is ready to retrieve from the Kinect
        /// </summary>
        /// <param name="sender"> object sending the event </param>
        /// <param name="e"> event arguments </param>
        void depthFrameReady(object sender, DepthImageFrameReadyEventArgs e)
        {
            Console.WriteLine("Depth Frame Received");
            if (frame_count < NUM_FRAMES) // if we have not retrieved the necessary number of frames 
            {
                using (DepthImageFrame depth_frame = e.OpenDepthImageFrame()) // retrieve the frame
                {
                    if (depth_frame != null) // check for an invalid frame
                    {
                        sensor.Stop(); // temporarily disable the Kinect sensor
                        depth_data = new short[depth_frame.PixelDataLength]; // allocate space to hold the depth data
                        depth_frame.CopyPixelDataTo(depth_data); // copy the depth data to the array
                        depth_frames.Add(depth_data); // add the depth data to the list of frames   
                    }

                    frame_count++; // increment the number of frames that have been retrieved
                  
                    if (frame_count == NUM_FRAMES) // if we have all the frames we need
                    {
                        sensor.Stop();
                        depth_data = averageKinectDepth(depth_frames); // average the depth data from all the frames retrieved
                        return;
                        //Console.WriteLine(depth_data[0]);
                    }
                    sensor.Start();  // restart the sensor
                }
                Console.WriteLine("Done Processing Frame");
            }
        }

        /// <summary>
        /// colorFrameReady() is an event handler that executes each time a new color frame is ready for retrieval from the Kinect
        /// </summary>
        /// <param name="sender"> object sending the event </param>
        /// <param name="e"> event arguments </param>
        void colorFrameReady(object sender, ColorImageFrameReadyEventArgs e)
        {
            if (color_retrieved == false) // if we have not yet retrieved a color frame for processing
            {
                using (ColorImageFrame color_frame = e.OpenColorImageFrame())
                {
                    if (color_frame != null) // check for an invalid frame
                    {
                        sensor.Stop(); // temporarily disable the Kinect sensor
                        color_data = new byte[sensor.ColorStream.FramePixelDataLength]; // allocate space to hold the color data
                        color_frame.CopyPixelDataTo(color_data); // copy the color data to the array
                        color_bitmap = new WriteableBitmap(sensor.ColorStream.FrameHeight, sensor.ColorStream.FrameWidth, 96.0, 96.0, PixelFormats.Bgr32, null); // create a bitmap to hold the color data
                        try
                        {
                           // color_bitmap.WritePixels(new Int32Rect(0, 0, color_bitmap.PixelWidth, color_bitmap.PixelHeight), color_data, color_bitmap.PixelWidth * sizeof(int), 0); // write the color data to the bitmap
                        }
                        catch(IOException)
                        {
                            Console.WriteLine("ERROR: IOException");
                        }
                            // color_image.Source = color_bitmap;                                                                                                                                           
                        saveImage(color_bitmap); // save the image
                    }
                    sensor.Start();  // restart the sensor
                }
                color_retrieved = true; // indicates that a color frame has been retrieved and there is no need to retrieve another
            }
        }

        /// <summary>
        /// averageKinectDepth() takes multiple depth frames from the Kinect and averages them together to insure the overall accuracy of the data
        /// </summary>
        /// <param name="depth_frames"> a list of depth data frames that will be averaged together </param>
        /// <returns></returns>
        short[] averageKinectDepth(List<short[]> depth_frames)
        {
            short[] average_depth = new short[depth_frames[0].Length]; // temporary array to hold averaged depth data

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

           // File.WriteAllBytes("Depth.txt", average_depth);
            return average_depth;
        }

        /// <summary>
        /// saveImage() saves the color image retrieved from the Kinect
        /// </summary>
        /// <param name="color_bitmap"> the color bitmap that is being saved as an image </param>
        void saveImage(WriteableBitmap color_bitmap)
        {
            BitmapEncoder encoder = new PngBitmapEncoder(); // create a bitmap encoder

            encoder.Frames.Add(BitmapFrame.Create(color_bitmap)); // create a frame from the bitmap and add it to the encoder

            // create path information, label for saved image
            string time = System.DateTime.Now.ToString("hh'-'mm'-'ss", CultureInfo.CurrentUICulture.DateTimeFormat);
            string photo_path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            file_path = Path.Combine(photo_path, "KinectSnapshot-" + time + ".jpg");

            try
            {
                using (FileStream file = new FileStream(file_path, FileMode.Create))
                {
                    encoder.Save(file);
                }
            }
            catch(IOException)
            {
                Console.WriteLine("ERROR: Failed to save Kinect snapshot");
            }
        }

        /// <summary>
        ///  processResults() utlizes an array received from the C++ DLL to alert the user to the success/failure of the verification
        /// </summary>
        /// <param name="results"></param> the array containing the results of the verification process
        /// <param name="GUI"></param> the GUI that is displayed to the user
        public void processResults(int[] results, Form1 GUI)
        {
            if (results[4] == 5) // if the order is correct, all verification components must have been successful
            {
               GUI.profileStatus_Success(null, null);
               GUI.lengthStatus_Success(null, null);
               GUI.colorStatus_Success(null, null);
               GUI.quantityStatus_Success(null, null);
            }
            // if the order was not correct, determine which verification process failed
            else
            {
                if (results[0] == 1) // if profile verification failed
                    GUI.profileStatus_Failure(null, null);
                else // if profile verification failed
                    GUI.profileStatus_Success(null, null);

                if (results[1] == 2) // if length verification failed
                    GUI.lengthStatus_Failure(null, null);
                else // if length verification succeeded
                    GUI.lengthStatus_Success(null, null);

                if (results[2] == 3) // if color verification failed
                    GUI.colorStatus_Failure(null, null);
                else // if color verification succeeded
                    GUI.colorStatus_Success(null, null);

                if (results[3] == 4) // if quantity verification failed
                    GUI.quantityStatus_Failure(null, null);
                else // if quantity verification succeeded
                    GUI.quantityStatus_Success(null, null);
            }
        }

        /// <summary>
        /// terminateVerificationSoftware terminates the software
        /// </summary>
        public void terminateVerificationSoftware()
        {
            Console.WriteLine("Verification Software Terminated");
            
        }
     }

}

