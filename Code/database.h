/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

database.h - header file for the database software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				1/9/16			database class created, added connectDatabase(), queryDatabase(), and necessary variables


--------------------------------------------------------------------------------
*/
#ifndef DATABASE_H
#define DATABASE_H
#pragma once

#include <stdlib.h>
#include <string>
#include <occi.h>
#include <iostream>

using namespace std;

class database
{
public:
	database(); // class constructor
	oracle::occi::Connection* connectDatabase(string userName, string password, string connectString); // create a connection to Oracle database
	oracle::occi::ResultSet* queryDatabase(oracle::occi::Connection* conn, string query_string); // query the Oracle database
	~database(); // class destructor 

	oracle::occi::Environment* env; // Oracle Environment variable
	oracle::occi::Connection* conn; // Oracle Database Connection variable
	oracle::occi::Statement *query; // Oracle Statement variable for forming queries
	oracle::occi::ResultSet *result; // Oracle ResultSet variable for storing results of a query
};

#endif

