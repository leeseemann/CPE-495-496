/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

length.h - header file for the length verification software

*/
#ifndef LENGTH_H
#define LENGTH_H
#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>

class length
{
public:
	length(); // class constructor
	bool initialize();
	bool length_verified = false; // bool indicating the success/failure of the length verification software
	~length(); // class destructor 
};

#endif

