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


--------------------------------------------------------------------------------
*/

#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\driver.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\driver.cpp"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\profile.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\profile.cpp"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\length.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\length.cpp"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\color.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\color.cpp"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\quantity.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\quantity.cpp"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\database.h"
#include "A:\School\Spring 2016\CPE 496\Code\CPE_Senior_Design\Code\database.cpp"

extern "C" __declspec(dllexport) void Steelcase_Answer_Verification(short depth_data[])
{
	driver project_driver;
	project_driver.startup(depth_data);
}