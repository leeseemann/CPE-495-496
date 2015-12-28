/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

dll.cpp - creates the C++ DLL used by the C# wrapper

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		file created, created instance of driver class


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

extern "C" __declspec(dllexport) void Steelcase_Answer_Verification()
{
	driver project_driver;
	project_driver.startup();
}