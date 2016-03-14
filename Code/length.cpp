/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

length.cpp - source file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created, added initialize() function
Lee				3/14/16			modified initialize() to return bool based on success 

--------------------------------------------------------------------------------
TO DO
Elaine			Camera_calibration, edge detection, pixel count for length
*/
#include "length.h"

using namespace std;

length::length()
{
}

bool length::initialize()
{
	cout << "Initializing Length Verification Software" << endl;
	return length_verified;
}

length::~length()
{
}
