/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

database.cpp - source file for the database software

*/
#include "database.h"

using namespace std;

// Database class constructor
database::database()
{
}

// Create a connection to an oracle database
oracle::occi::Connection* database::connectDatabase(string userName, string password, string connectString)
{
	oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment(); // create Oracle environment
	oracle::occi::Connection *conn = env->createConnection(userName, password, connectString); // create connection to Oracle database
	
	return conn;
}

// Query the Oracle database
oracle::occi::ResultSet* database::queryDatabase(oracle::occi::Connection* conn, string query_string)
{
		query = conn->createStatement(query_string); // form Oracle database query
		result = query->executeQuery(); // execute the database query

		return result;
}

// Database class destructor
database::~database()
{
}
