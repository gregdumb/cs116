// Gregory Brisebois
// CS116 Ron Sha

#include <iostream>
#include <iomanip>
#include <string>
 
using namespace std;

double finalpay(double, double);

int main ()
{	
	// Set up some initial variables
	string fname, lname;
	double salary = 0, hours = 0;
	
	// Print initial info screen
	cout << "BRISEBOIS, GREGORY - CS116 FALL 2015" << endl;
	cout << "---" << endl;
	
	// Get inputs
	cout << "Welcome! Please enter employee first name: ";
	cin >> fname;
	
	cout << "Please enter last name: ";
	cin >> lname;
	
	cout << "Please enter hourly salary: $";
	cin >> salary;
	
	cout << "Please enter hours worked: ";
	cin >> hours;
	
	cout << "---" << endl;
	
	// Print outputs
	cout << "* Payroll Information" << endl;
	cout << "* Name: " << fname << " " << lname << endl;
	cout << "* Wage: $" << fixed << setprecision(2) << salary << "/hour" << endl;
	cout << "* Hours Worked: " << hours << endl;
	cout << "* Pay: $" << fixed << setprecision(2) << finalpay(salary, hours) << endl;
	cout << setw(20) << "* Approved By: Gregory Brisebois" << endl;
	
	cout << "---" << endl;
}

// Gets the pay amount accounting for overtime
double finalpay(double salary, double hours)
{
	double returnvalue = 0;
	
	if (hours > 40)
	{
		returnvalue = salary * 40 + salary * 1.5 * (hours - 40);
	}
	else
	{
		returnvalue = salary * hours;
	}
	
	return returnvalue;
}
