/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

length.h - header file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		Class Created, Added initialize() Function


--------------------------------------------------------------------------------
*/

#ifndef LENGTH_H
#define LENGTH_H
#pragma once

class length
{
public:
	length(); // class constructor
	void initialize();
	~length(); // class destructor 
};

#endif

