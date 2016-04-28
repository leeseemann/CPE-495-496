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
Lee				3/25/16			added code needed to read data from a file if needed
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
#include <fstream>
#include<cmath>
#include <stdlib.h>
#include <stdio.h>

#define DEPTH_WIDTH 640
#define DEPTH_HEIGHT 480
#define COLOR_WIDTH 1280
#define COLOR_HEIGHT 960

// define the size of the Kinect frame
//#define width 640
//#define height 480
//RNG rng(12345);
using namespace cv;
using namespace std;

enum PROFILE
{
	error,
	square,
	thin,
	oval
};

class profile
{
public:
	profile(); // class constructor

	bool initialize();
	void edgeDetection();
	void readDataFromFile();
	PROFILE detectProfile(int, int, int, int, int, int, int, int, short[DEPTH_WIDTH*DEPTH_HEIGHT]);
	void shiftDepthArray(short[DEPTH_WIDTH*DEPTH_HEIGHT]);

	bool profile_verified = false; // bool indicating the success/failure of the profile verification software

	Mat image; // the original image before edge detection
	Mat destination; // the final data after edge detection
	Mat hsv;
	vector<Mat> hsv_channels; // vector containing the three channels of data in the HSV color space
	Mat hsv_H, hsv_S, hsv_V; // holds the data for the three channels in the HSV color space
	Mat shifted_H, canny_H;
	int shift_amount; // the amount the Hue space was shifted
	char* window_name = "Edge Detection";
	char* file_name;
	short* depth_data; // array to hold the depth data
	int num = 12345;

	Mat src;
	Mat src_gray;

	Mat src_gray2;

	int thresh = 100; // used to be 100

	int max_thresh = 255;

	int thresh2 = 200;

	int max_thresh2 = 255;

	Mat drawing;

	RNG rng;

	Mat threshold_output;

	Mat drawing2;

	Mat cdst;

	Mat dst;

	char* source_window2 = "Source image";

	char* corners_window2 = "Corners detected";




	/// Function header

	void static thresh_callback(int, void*);

	void static thresh_callback2(int, void*);

	void static cornerHarris_demo(int, void*);
	
	~profile(); // class destructor 


};

static profile instance;

#endif


