/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.h - header file for main.cpp

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				1/9/16		file created, variables needed for OCCI added


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
#include <string.h>
#include <occi.h>

using namespace std;

driver project_driver; // driver used by the C# wrapper
database oracle_database; // instance of database class for interacting with Oracle database

// variables for connecting to and querying the Oracle database
string userName;
string password;
string connectString;
string query;
oracle::occi::Connection* conn;
oracle::occi::ResultSet* result;

#endif