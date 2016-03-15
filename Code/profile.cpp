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

void profile::edgeDetection()
{
	// load an image into src
	char* file_name = "C:\\Users\\Lee Seemann\\Desktop\\KinectSnapshot.png";
	source = imread(file_name);
	
	if (!source.data)
	{
		cout << "ERROR: No image loaded for edge detection";
		profile_verified = false;
		return;
	}

	destination.create(source.size(), source.type()); // create a matrix of the same type and size as src
	cvtColor(source, source_gray, CV_BGR2GRAY); // convert the image to grayscale
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	cannyThreshold(0, 0);

	waitKey(0);


	//cvtColor(source, hsv, CV_BGR2HSV);
	//split(hsv, hsv_channels);

	//hsv_H = hsv_channels[0];
	//hsv_S = hsv_channels[1];
	//hsv_V = hsv_channels[2];

	return;
}


void profile::cannyThreshold(int, void*)
{
	blur(source_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, low_threshold, low_threshold*ratio, kernel_size);
	destination = Scalar::all(0);
	source.copyTo(destination, detected_edges);
	imshow(window_name, destination);
}

profile::~profile()
{
}
