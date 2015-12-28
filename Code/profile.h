/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

profile.h - header file for the profile verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		profile class created, added initialize() function


--------------------------------------------------------------------------------
*/

#ifndef PROFILE_H
#define PROFILE_H
#pragma once

class profile
{
public:
	profile(); // class constructor
	void initialize();
	~profile(); // class destructor 
};

#endif


