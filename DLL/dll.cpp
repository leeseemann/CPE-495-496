/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

dll.cpp - creates the C++ DLL used by the C# wrapper

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		file created, created instance of driver class
Lee				1/9/16			added database.h and database.cpp
Lee				1/31/16			added the parameter depth_data
Lee				3/8/16			added the parameter color_image
Lee				3/14/16			added int* to pass the success/failure array to the C# wrapper

--------------------------------------------------------------------------------
*/

#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\driver.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\driver.cpp"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\profile.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\profile.cpp"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\length.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\length.cpp"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\color.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\color.cpp"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\quantity.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\quantity.cpp"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\database.h"
#include "C:\Users\Lee Seemann\Documents\GitHub\CPE_Senior_Design\Code\database.cpp"
#include <iostream>

extern "C" __declspec(dllexport) int* Steelcase_Answer_Verification(short depth_data[])
{
	driver project_driver;
	int* results;
	results = project_driver.startup(depth_data);
	return results;
}
