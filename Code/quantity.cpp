/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

quantity.cpp - source file for the quantity verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created, added initialize() function
Lee				3/14/16			modified initialize() to return bool based on success

--------------------------------------------------------------------------------
*/
#include "quantity.h"

using namespace std;

quantity::quantity()
{
}

bool quantity::initialize()
{
	cout << "Initializing Quantity Verification Software" << endl;
	return quantity_verified;
}

quantity::~quantity()
{
}
