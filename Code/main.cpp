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

#include "main.h"

int main()
{
	project_driver.startup();

	// Create a test database connection and simple query 
	userName = "hr";
	password = "uah";
	connectString = "";
	query = "select num from data";
	conn = oracle_database.connectDatabase(userName, password, connectString);
	result = oracle_database.queryDatabase(conn, query);

	while (result->next())
		cout << "result: " << result->getInt(1) << endl;

	cin.get(); // allows the output of the program to be viewed
	return 0;
}
