// Created by Gregory Brisebois with content from Ron Q. Sha

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "dbconnect.h"
#include <string>
#include <cstring>
#include <sstream>

// We use a custom namespace to fix our to_string function
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace patch;
 
 // Course requirement - prints my own name on the console
void printMyName()
{
	cout << "-------------------------" << endl;
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "With files provided by Ron Sha" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

// Checks if a value is within two other values
// @return - true if it is
bool inRange(int value, int min, int max)
{
	return value >= min && value <= max;
}

// Prompts the user for an input and rejects it if it is not valid
// @param promt - custom string to use for prompt
// @param min - min acceptable value
// @param max - max acceptable value
// @return - the inputted value
int getValidIntInput(string prompt = "Enter value: ", int min = 0, int max = 0)
{
	// To hold the input
	int input = -1;
	
	// Used to track if the input is valid
	bool inputOkay = true;
	
	// Loop until the user gives us a good value
	do
	{
		inputOkay = true;
				
		cout << prompt;
		cin >> input;
		
		// Handle if input was non numeric
		if(!cin)
		{
			cout << "Entered value must be a number, please try again." << endl;
			inputOkay = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		
		// Handle if input was out of range
		else if(!inRange(input, min, max))
		{
			cout << "Entered value must be between " << min << " and " << max << ", please try again." << endl;
			inputOkay = false;
			
		}
	}
	while(!inputOkay);
	
	return input;
}

// Returns the mySQL code from the user's entered int
// @param sortInt - user entered choice
// @return - string of SQL
string getSortFromInt(int sortInt)
{
	switch(sortInt)
	{
		case 0:
			return "order by winename";
			break;
		
		case 1:
			return "order by price";
			break;
			
		case 2:
			return "order by rating desc";
			break;
		
		case 3:
			return "order by vintage";
			break;
			
		case 4:
			return "order by wineType, vintage";
			break;
	}
}

// Returns the mySQL code from the user's entered int
// @param sortInt - user entered choice
// @return - string of SQL

string getTypeFromInt(int typeInt)
{
	switch(typeInt)
	{
		case 0:
			return "";
			break;
		
		case 1:
			return " and wineType = 'White'";
			break;
			
		case 2:
			return " and wineType = 'Red'";
			break;
	}
}

// Prompts the user for range and sort choices, and assembles a
// matching mySQL statement.
// @return - the SQL statement in string form.
string getSqlStatement()
{
	cout << "Welcome to the wine database frontend!  Please enter desired ranges." << endl;
	
	int priceMin = getValidIntInput("Enter minimum price: ", 0, 9999);
	int priceMax = getValidIntInput("Enter maximum price: ", priceMin, 9999);
	
	int scoreMin = getValidIntInput("Enter minimum score: ", 0, 100);
	int scoreMax = getValidIntInput("Enter maximum score: ", scoreMin, 100);
	
	int yearMin = getValidIntInput("Enter minimum vintage: ", 1900, 2015);
	int yearMax = getValidIntInput("Enter maximum vintage: ", yearMin, 2015);
	
	string wineType = getTypeFromInt( getValidIntInput("\nWhat wine types would you like? 0 = all; 1 = white; 2 = red: ", 0, 2) );
	
	string sortType = getSortFromInt( getValidIntInput("\nHow would you like to sort?\n0 = by name only;\n1 = by price, then name;\n2 = by rating, then name;\n3 = by vintage, then name;\n4 = by type, then vintage:  ", 0, 4) );
	
	string statement = "select * from wineInfo where price >= " + to_string(priceMin) + " and price <= " + to_string(priceMax) +
												" and rating >= " + to_string(scoreMin) + " and rating <= " + to_string(scoreMax) +
												" and vintage >= " + to_string(yearMin) + " and vintage <= " + to_string(yearMax) +
												wineType + " " + sortType + ", winename;";
	
	return statement;
}

int main()
{
	printMyName(); // Course requirement
	
	
	
	int wideColumn = 50; // column width for names
	int shortColumn = 10; // column width for non-names
	
	// Make a bar to use for the ends (formatting)
	string bar = "|";
	bar.append(shortColumn * 4 + wideColumn + 2, '-');
	bar.append("|");
	
	MYSQL *conn;	// the connection
	MYSQL_RES *res;	// the results
	MYSQL_ROW row;	// the results row (line by line)
	
	struct connection_details mysqlD;
	mysqlD.server = (char *)"localhost";	// where the mysql database is
	mysqlD.user = (char *)"root";			// the root user of mysql	
	mysqlD.password = (char *)"password";	// the password of the root user in mysql
	mysqlD.database = (char *)"mysql";		// the databse to pick
	
	// connect to the mysql database
	conn = mysql_connection_setup(mysqlD);
	
	// open our database
	res = mysql_perform_query(conn, (char *)"use wine");
	
	// Get the needed query in the form of a string
	string statement = getSqlStatement();
	
	// format our query string
	string argString = statement;
	char *myArg = new char[argString.length() + 1];
	strcpy(myArg, argString.c_str());
	
	// perform our query string
	res = mysql_perform_query(conn, myArg);
	
	delete [] myArg;
	
	// Printing out the header
	cout << bar << endl;
	cout << "| " << setw(wideColumn)
				<< left << "Wine Name"
				<< setw(shortColumn)
				<< "Vintage" << setw(shortColumn)
				<< "Rating" << setw(shortColumn)
				<< "Price" << setw(shortColumn)
				<< "Type" << " |" << endl;
				
	// Iterate through each row of data and print it
	while ((row = mysql_fetch_row(res)) !=NULL)
	{
			cout << "| " << setw(wideColumn) << left << row[0]   // coulumn (field) #1 - Wine Name
			<< setw(shortColumn) << row[1] // field #2 - Vintage
			<< setw(shortColumn) << row[2] // field #3 - Rating
			<< setw(shortColumn) << row[3] // field #4 - Price
			<< setw(shortColumn) << row[4] // field #5 - Wine type
			<< " |" << endl;
	}
	
	// Close the bottom with another horizontal bar
	cout << bar << endl;
	
	/* clean up the database result set */
	mysql_free_result(res);
	/* clean up the database link */
	mysql_close(conn);
	
	return 0;
}
