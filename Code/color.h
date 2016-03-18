/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

color.h - header file for the color verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		color class created, added initialize() function
Lee				3/10/16			added bool to track the success of the color verification


--------------------------------------------------------------------------------
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
	bool color_verified = false;
	~color(); // class destructor 
};

#endif

