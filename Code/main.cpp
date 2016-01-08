/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

main.cpp - primary source file of the project

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/22/15		file created
Lee				12/28/15		added instance of driver class
Lee				1/8/16			added OCCI functionality, tested local database connection
--------------------------------------------------------------------------------
*/

using namespace std;

#include "driver.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <occi.h>


int main()
{
	driver driver;
	driver.startup();

	const string userName = "hr";
	const string password = "uah";
	const string connectString = "alias";

	oracle::occi::Environment *env = oracle::occi::Environment::createEnvironment();
	oracle::occi::Connection *conn = env->createConnection(userName, password);

	oracle::occi::Statement *query = conn->createStatement("select num from data");
	oracle::occi::ResultSet *result = query->executeQuery();

	while (result->next())
		cout << "result: " << result->getInt(1) << endl;

	query->closeResultSet(result);
	conn->terminateStatement(query);
	env->terminateConnection(conn);
	oracle::occi::Environment::terminateEnvironment(env);

	cin.get(); // allows the output of the program to be viewed
	return 0;
}
