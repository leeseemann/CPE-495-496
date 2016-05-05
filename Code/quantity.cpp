/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

quantity.cpp - source file for the quantity verification software

*/
#include "quantity.h"

using namespace std;

// Quantity class constructor
quantity::quantity()
{
}

bool quantity::initialize()
{
	cout << "Initializing Quantity Verification Software" << endl;
	return quantity_verified;
}

// Quantity class destructor
quantity::~quantity()
{
}
