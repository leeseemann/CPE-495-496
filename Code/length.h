/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

length.h - header file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		length class created, added initialize() function
Lee				3/10/16			added bool to track the success of the length verification


--------------------------------------------------------------------------------
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
	bool length_verified = false;
	~length(); // class destructor 
};

#endif

