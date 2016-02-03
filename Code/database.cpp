/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

database.cpp - source file for the database software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				1/9/16			file created, added connectDatabase(), queryDatabase(), disconnectDatabase()


--------------------------------------------------------------------------------
*/
#include "database.h"

using namespace std;

database::database()
{
}
oracle::occi::Connection* database::connectDatabase(string userName, string password, string connectString)
{
	oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment(); // create Oracle environment
	oracle::occi::Connection *conn = env->createConnection(userName, password, connectString); // create connection to Oracle database
	
	return conn;
}

oracle::occi::ResultSet* database::queryDatabase(oracle::occi::Connection* conn, string query_string)
{
		query = conn->createStatement(query_string); // form Oracle database query
		result = query->executeQuery(); // execute the database query

		return result;
}

database::~database()
{
	// terminate the Oracle database connection and environment
	//query->closeResultSet(result);
	//conn->terminateStatement(query);
	//env->terminateConnection(conn);
	//oracle::occi::Environment::terminateEnvironment(env);
}
