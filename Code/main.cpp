/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.cpp - primary source file of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created
Lee				12/28/15		added instance of driver class

--------------------------------------------------------------------------------
*/
using namespace std;

#include "main.h"

/// main() is only necessary when the C++ code is run in isolation, when the C# driver is used main() is bypassed
int main()
{
	project_driver.startup(depth_data);
	cin.get(); // allows the output of the program to be viewed
	return 0;
}

