class Employee
{
public:
	// Constructors
	Employee();
	Employee(string initialName, double initialSalary);
	
	// Accessors
	double getSalary() const;
	string getName() const;
	
	// Mutators
	void setSalary(double newSalary);

private:
	// Variables
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
