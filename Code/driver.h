/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

driver.h - header file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		driver class created, added startup() function


--------------------------------------------------------------------------------
*/

#ifndef DRIVER_H
#define DRIVER_H
#pragma once

#include "profile.h"
#include "length.h"
#include "color.h"
#include "quantity.h"

class driver
{
public:
	driver();
	void startup();
	~driver();

	profile verify_profile;
	length verify_length;
	color verify_color;
	quantity verify_quantity;
};

#endif

