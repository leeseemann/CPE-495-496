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

	return profile_verified;
}

profile::~profile()
{
}
