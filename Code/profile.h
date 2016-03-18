/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

profile.h - header file for the profile verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		profile class created, added initialize() function
Lee				1/16/16			added header files for Kinect SDK
Lee				1/25/16			added Kinect and OpenGL variables/functions for retrieving Kinect frame
Lee				1/25/16			added glut variables/functions to display Kinect frame
Lee				2/19/16			modified project to utilize OpenCV, used profile.h to test
Lee				3/10/16			added bool to track the success of the profile verification
Jacob/Lee		3/15/16			implemented edge detection software
Jacob/Lee		3/16/16			modified edge detection to detect edges of a certain color using hsv color space 
--------------------------------------------------------------------------------
*/
#ifndef PROFILE_H
#define PROFILE_H
#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <NuiSensor.h>
#include <opencv2\imgproc\imgproc.hpp> 
#include <opencv2\highgui\highgui.hpp>

// define the size of the Kinect frame
#define width 640
#define height 480

using namespace cv;
using namespace std;

class profile
{
public:
	profile(); // class constructor

	bool initialize();
	void edgeDetection();
	bool profile_verified = false;

	Mat image; // the original image before edge detection
	Mat destination; // the final data after edge detection
	Mat hsv;
	vector<Mat> hsv_channels; // vector containing the three channels of data in the HSV color space
	Mat hsv_H, hsv_S, hsv_V; 
	Mat shifted_H, canny_H;
	int shift_amount; // the amount the Hue space was shifted
	char* window_name = "Edge Detection";
	char* file_name;

	
	~profile(); // class destructor 


};

static profile* instance;

#endif


