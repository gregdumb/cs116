// Gregory Brisebois
// CS116 Ron Sha

#include <iostream>
#include <string>
 
using namespace std;

double finalpay(double, double);

int main ()
{	
	cout << "BRISEBOIS, GREGORY - CS116 FALL 2015" << endl;
	cout << "---" << endl;
	cout << "Welcome! Please enter employee first name: ";
	
	string fname, lname;
	double salary = 0, hours = 0;
	
	cin >> fname;
	
	cout << "Please enter last name: ";
	
	cin >> lname;
	
	cout << "Please enter hourly salary: $";
	
	cin >> salary;
	
	cout << "Please enter hours worked: ";
	
	cin >> hours;
	
	cout << "---" << endl;
	
	cout << "Payroll Information" << endl;
	cout << "Name: " << fname << " " << lname << endl;
	cout << "Wage: $" << salary << "/hour" << endl;
	cout << "Hours Worked: " << hours << endl;
	cout << "Overtime Hours Worked: " << ((hours > 40) ? (hours - 40) : 0) << endl;
	cout << "Pay: $" << finalpay(salary, hours) << endl;
	cout << "Approved By: Gregory Brisebois" << endl;
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
