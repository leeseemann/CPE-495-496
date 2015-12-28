/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

quantity.h - header file for the quantity verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		Class Created, Added initialize() Function


--------------------------------------------------------------------------------
*/

#ifndef QUANTITY_H
#define QUANTITY_H
#pragma once

class quantity
{
public:
	quantity(); // class constructor
	void initialize();
	~quantity(); // class destructor 
};

#endif

