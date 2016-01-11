/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

driver.cpp - source file for the length verification software

Modification History
Developer		Date			Comments
--------------------------------------------------------------------------------
Lee				12/28/15		file created, added startup() function
Lee				1/9/16			used OCCI to created Oracle database connection, executed test query


--------------------------------------------------------------------------------
*/
#include "driver.h"

using namespace std;

driver::driver()
{
}

void driver::startup()
{
	verify_profile.initialize(); // initialize profile verification
	verify_length.initialize(); // initialize length verification
	verify_color.initialize(); // initialize color verification
	verify_quantity.initialize(); // initialize quantity verification

	// connect to Oracle database
	userName = "hr";
	password = "uah";
	connectString = "";
	conn = oracle_db.connectDatabase(userName, password, connectString);

	// query the Oracle database
	query_string = "select num from data";
	result_query = oracle_db.queryDatabase(conn, query_string);
	while (result_query->next())
		cout << "result: " << result_query->getInt(1) << endl;

	return;
}

driver::~driver()
{
}
