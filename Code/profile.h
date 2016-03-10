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
--------------------------------------------------------------------------------
*/
#ifndef PROFILE_H
#define PROFILE_H
#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <Ole2.h>
#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <NuiSensor.h>
//#include <opencv\cv.h> // test opencv, may not be needed

// define the size of the Kinect frame
#define width 640
#define height 480

class profile
{
public:
	profile(); // class constructor

	void initialize();
	bool profile_verified = false;
	~profile(); // class destructor 


};

static profile* instance;

#endif


