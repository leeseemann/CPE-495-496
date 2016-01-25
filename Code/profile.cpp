/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

profile.cpp - source file for the profile verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created, added initialize() function
Lee				1/25/16			added initialize_Kinect() and getKinectFrame() functions

--------------------------------------------------------------------------------
*/
#include "profile.h"

using namespace std;

profile::profile()
{
}

void profile::initialize()
{
	cout << "Initializing Profile Verification Software" << endl; \
	init_Kinect = initialize_Kinect();

	return;
}

bool profile::initialize_Kinect()
{
	int numSensors;
	if (NuiGetSensorCount(&numSensors) < 0 || numSensors < 1) // determine if a Kinect is attached and running
	{
		cout << "ERROR: No Kinect Found" << endl;
		return false;
	}
	if (NuiCreateSensorById(0, &sensor) < 0)
	{
		cout << "ERROR: Kinect Sensor Uninitialized" << endl;
		return false;
	}

	sensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_DEPTH | NUI_INITIALIZE_FLAG_USES_COLOR); // initialize the Kinect and specify depth/color and flags
	sensor->NuiImageStreamOpen(
		NUI_IMAGE_TYPE_COLOR,          // depth or rgb camera
		NUI_IMAGE_RESOLUTION_640x480,  // image resolution
		0,							   // image stream flags
		2,							   // number of frames to buffer
		NULL,						   // event handler
		&rgbStream);

	return sensor;
}

void profile::getKinectFrame(GLubyte* destination)
{
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT lockedRect;

	if (sensor->NuiImageStreamGetNextFrame(rgbStream, 0, &imageFrame) < 0) // retrieve a frame from Kinect
	{
		cout << "ERROR: Failed to Retrieve Kinect Frame" << endl;
		return;
	}

	texture = imageFrame.pFrameTexture;
	texture->LockRect(0, &lockedRect, NULL, 0); // lock the frame

	if (lockedRect.Pitch != 0) // check to see if there is data in the frame
	{
		current = (const unsigned char*)lockedRect.pBits;
		dataEnd = current + (width*height) * 4;

		while (current < dataEnd) // iterate through the frame
		{
			*destination++ = *current++;
		}
	}

	texture->UnlockRect(0); // unlock the frame
	sensor->NuiImageStreamReleaseFrame(rgbStream, &imageFrame); // release the frame
}

profile::~profile()
{
}
