#include <iostream>
#include <string>

using namespace std;

// *************************************************
// Employee Class

class Employee
{
public:
	// Constructors
	Employee();
	Employee(string initialName, double initialSalary);
	
	double getSalary() const;
	
	void setSalary(double newSalary);
	string getName() const;

private:

	string name;
	double salary;
};

// Default Constructor
Employee::Employee()
{
	name = "";
	salary = 0;
}

// Custom Constructor
Employee::Employee(string initialName, double initialSalary)
{
	name = initialName;
	salary = initialSalary;
}

void Employee::setSalary(double newSalary)
{
	salary = newSalary;
}

double Employee::getSalary() const
{
	return salary;
}

string Employee::getName() const
{
	return name;
}

// *************************************************
// Manager Class

class Manager : public Employee
{
};

int main()
{
}
