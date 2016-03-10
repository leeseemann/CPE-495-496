/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.h - header file for main.cpp

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				1/9/16		file created, moved variable declarations from main.cpp


--------------------------------------------------------------------------------
*/
#ifndef MAIN_H
#define MAIN_H
#pragma once

#include "driver.h"
#include "database.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

driver project_driver; // driver used by the C# wrapper
short depth_data [3] = { 1,2,3 }; // used for testing purposes
string file_path = "test file path";

#endif