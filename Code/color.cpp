/* University of Alabama in Huntsville 
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

color.cpp - source file for the color verification software

*/
#include "color.h"

using namespace std;

color::color()
{
}

bool color::initialize()
{
	cout << "Initializing Color Verification Software" << endl;
	return color_verified;
}

color::~color()
{
}
