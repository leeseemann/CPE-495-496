/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

length.cpp - source file for the length verification software

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
