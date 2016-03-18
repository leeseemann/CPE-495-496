/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

profile.cpp - source file for the profile verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created, added initialize() function
Lee				1/25/16			added initialize_Kinect() and getKinectFrame() functions
Lee				1/25/16			added glut functions to display Kinect frame
Lee				3/9/16			removed Kinect and glut functions, Kinect code now implemented in C# wrapper
Lee				3/14/16			modified initialize() to return bool based on success
Jacob/Lee		3/15/16			implemented edge detection software
Jacob/Lee		3/16/16			modified edge detection to detect edges of a certain color using hsv color space
--------------------------------------------------------------------------------
*/
#include "profile.h"

using namespace std;

profile::profile()
{

}

bool profile::initialize()
{
	cout << "Initializing Profile Verification Software" << endl; 
	edgeDetection();

	return profile_verified;
}


// The edgeDetection() function performs Canny edge detection of an image containing the Answer component using the HSV color space
void profile::edgeDetection()
{
	
	file_name = "C:\\Users\\Lee Seemann\\Desktop\\KinectSnapshot.png";
	image = imread(file_name); // load an image for processing
	
	if (!image.data) // if the image in invalid, exit the software
	{
		cout << "ERROR: No image loaded for edge detection";
		profile_verified = false;
		return;
	}

	cvtColor(image, hsv, CV_BGR2HSV);  // convert image color to hsv format
	
	// separate the hsv data into 3 channels (Hue-H, Saturation-S, Value-V)
	split(hsv, hsv_channels);  
	hsv_H = hsv_channels[0];
	hsv_S = hsv_channels[1];
	hsv_V = hsv_channels[2];

	// Hue space is a circular/angular value meaning the highest and lowest value are very close together
	// This can result in bright artifacts at the edges of an object, we shift the entire Hue space to overcome this
	shifted_H = hsv_H.clone();
	shift_amount = 25;

	for (int i = 0; i < shifted_H.rows; i++)
		for (int j = 0; j < shifted_H.cols; j++)
		{
			shifted_H.at<unsigned char>(i, j) = (shifted_H.at<unsigned char>(i, j) + shift_amount) % 180;
		}

	// Perform canny edge detection
	Canny(shifted_H, canny_H, 100, 50);

	// display the results of the edge detection
	destination = Scalar::all(0);
	image.copyTo(destination, canny_H);
	imshow(window_name, destination);

	waitKey(0); 

	return;
}

profile::~profile()
{
}
