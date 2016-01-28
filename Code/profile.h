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
#include <gl\GL.h>
#include <gl\GLU.h>
#include <glut.h>

// define the size of the Kinect frame
#define width 640
#define height 480

class profile
{
public:
	profile(); // class constructor

	void initialize();

	// Kinect Functions
	bool initialize_Kinect();	// initialize the Kinect
	void getKinectFrame(GLubyte* destination);  // retrieve a frame from the Kinect

	// OpenGL Functions
	bool initialize_glut();
	static void draw_wrapper();
	void drawKinectFrame();
	bool initialize_camera();

	//Kinect variables
	HANDLE rgbStream;  // identifier of the Kinect RGB camera
	INuiSensor* sensor; // Kinect sensor
	bool init_Kinect = false;  // was Kinect successfully initialized
	NUI_IMAGE_FRAME imageFrame; // structure containing the metadata of the Kinect frame
	NUI_LOCKED_RECT lockedRect; // pointer to the actual data in the Kinect frame
	INuiFrameTexture* texture;
	const unsigned char* current; // used to iterate through Kinect frame
	const unsigned char* dataEnd; // used to iterate through Kinect frame

	// OpenGL Variables
	GLuint textureID;	// ID of the texture to contain RGB data from Kinect
	GLubyte data[width * height * 4];  // array containing the texture data	
	bool init_glut = false;
	bool init_camera = false;
	int myargc;
	char* myargv[2];

	~profile(); // class destructor 
};

static profile* instance;

#endif


