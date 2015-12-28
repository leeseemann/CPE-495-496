/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.cpp - primary source file of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		File Created, Tested initialize() Functions


--------------------------------------------------------------------------------
*/

using namespace std;

#include "main.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

int main()
{
	verify_profile.initialize(); // initialize profile verification
	verify_length.initialize(); // initialize length verification
	verify_color.initialize(); // initialize color verification
	verify_quantity.initialize(); // initialize quantity verification

	cin.get(); // allows the output of the program to be viewed
	return 0;
}