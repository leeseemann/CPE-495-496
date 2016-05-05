/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

color.h - header file for the color verification software

*/
#ifndef COLOR_H
#define COLOR_H
#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>

class color
{
public:
	color(); // class constructor
	bool initialize();
	bool color_verified = false; // bool indicating the success/failure of the color software
	~color(); // class destructor 
};

#endif

