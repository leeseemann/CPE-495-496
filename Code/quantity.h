/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

quantity.h - header file for the quantity verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		quantity class created, added initialize() function
Lee				3/10/16			added bool to track the success of the quantity verification

--------------------------------------------------------------------------------
*/
#ifndef QUANTITY_H
#define QUANTITY_H
#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>

class quantity
{
public:
	quantity(); // class constructor
	bool initialize();
	bool quantity_verified = false; // bool indicating the success/failure of the quantity verification
	~quantity(); // class destructor 
};

#endif

