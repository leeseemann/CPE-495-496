/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

color.h - header file for the color verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		color class created, added initialize() function


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
	void initialize();
	~color(); // class destructor 
};

#endif

