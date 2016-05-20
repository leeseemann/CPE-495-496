/* University of Alabama in Huntsville
2015-2016 CPE Senior Design - Steelcase Answer Pack Verification
Elaine Boyd, Jacob Brooks, Devon Eastin, Lee Seemann

driver.h - header file for the length verification software

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
#include <fstream>

using namespace std;

class driver
{
public:
	driver();
	int* startup(short depth_data[]);
	void printDataToFile(short data[]);
	~driver();

	string file_path; // set this to a constant value that will always hold the location of the color image for processing
	profile verify_profile; // instance of the profile verification class
	length verify_length;  // instance of the length verification class
	color verify_color;  // instance of the color verification class
	quantity verify_quantity; // instance of the quantity verification class
	enum options:int{wrong_profile = 1, wrong_length = 2, wrong_color = 3, wrong_quantity = 4, correct = 5}; // enum containing possible results of the verification process

	int results[4];

	bool is_profile_correct; // bool indication the success/failure of the profile verification
	bool is_length_correct; // bool indication the success/failure of the length verification
	bool is_color_correct; // bool indication the success/failure of the color verification
	bool is_quantity_correct; // bool indication the success/failure of the quantity verification

	// variables needed to connect to and query test Oracle database
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

