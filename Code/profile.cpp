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
--------------------------------------------------------------------------------
*/
#include "profile.h"

using namespace std;

profile::profile()
{

}

void profile::initialize()
{
	cout << "Initializing Profile Verification Software" << endl; 
	
	/*init_glut = initialize_glut();
	if (init_glut == false)
		cout << "ERROR: GLUT not initialized" << endl;
	else
		cout << "Initializing GLUT Software" << endl;

	init_Kinect = initialize_Kinect();
	if (init_Kinect == false)
		cout << "ERROR: Kinect not initialized" << endl;
	else
		cout << "Initializing Kinect Sensor" << endl;

	init_camera = initialize_camera();
	if (init_camera == false)
		cout << "ERROR: Camera not initialized" << endl;
	else
		cout << "Initializing Camera" << endl;

	glutMainLoop(); // glut function that calls draw_wrapper*/

	return;
}

/*bool profile::initialize_Kinect()
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

	// initialize sensor
	sensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_DEPTH | NUI_INITIALIZE_FLAG_USES_COLOR); // initialize the Kinect and specify depth/color as flags
	sensor->NuiImageStreamOpen(
		NUI_IMAGE_TYPE_COLOR,          // depth or rgb camera
		NUI_IMAGE_RESOLUTION_640x480,  // image resolution
		0,							   // image stream flags
		2,							   // number of frames to buffer
		NULL,						   // event handler
		&rgbStream);

	return sensor;
}*/

/*bool profile::initialize_glut()
{
	instance = this;
	glutInit(&myargc, myargv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(width, height);
	glutCreateWindow("Kinect Image");
	glutDisplayFunc(draw_wrapper);
	glutIdleFunc(draw_wrapper);
	return true;
}

bool profile::initialize_camera()
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height,
		0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (GLvoid*)data);
	glBindTexture(GL_TEXTURE_2D, 0);

	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
	glEnable(GL_TEXTURE_2D);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return true;
}*/

/*void profile::getKinectFrame(GLubyte* destination)
{
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

void profile::draw_wrapper()
{
	instance->drawKinectFrame();
}

void profile::drawKinectFrame()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
	getKinectFrame(data);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (GLvoid*)data);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0, 0, 0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(width, 0, 0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(width, height, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0, height, 0.0f);
	glEnd();

	glutSwapBuffers();
}*/

profile::~profile()
{
}
