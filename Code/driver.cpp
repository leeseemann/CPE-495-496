/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

driver.cpp - source file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		file created, added startup() function


--------------------------------------------------------------------------------
*/
#include "driver.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

driver::driver()
{
}

void driver::startup()
{
	verify_profile.initialize(); // initialize profile verification
	verify_length.initialize(); // initialize length verification
	verify_color.initialize(); // initialize color verification
	verify_quantity.initialize(); // initialize quantity verification
	return;
}

driver::~driver()
{
}
