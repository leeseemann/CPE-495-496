/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

driver.h - header file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		driver class created, added startup() function
Lee				1/9/16			added OCCI and database connection variables, 
Lee				1/31/16			modified startup() to receive data from C# wrapper

--------------------------------------------------------------------------------
*/
#ifndef DRIVER_H
#define DRIVER_H
#pragma once

#include "profile.h"
#include "length.h"
#include "color.h"
#include "quantity.h"
#include "database.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

class driver
{
public:
	driver();
	void startup(short depth_data);
	~driver();

	profile verify_profile;
	length verify_length;
	color verify_color;
	quantity verify_quantity;

	string userName;
	string password;
	string connectString;
	string query_string;
	database oracle_db;
	oracle::occi::Connection* conn;
	oracle::occi::ResultSet* result_query;
	oracle::occi::Statement* query;
};

#endif

