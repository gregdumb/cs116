class Manager : public Employee
{
	public:
	
	// Constructors
	Manager();
	Manager(string initialName, double initialSalary, string initialDepartment);
	
	// Accessors
	string getDepartment() const;
	void printInfo();
	
	private:
	// Variables
	string department;
};

// Default Constructor
Manager::Manager() : Employee()
{
	department = "";
}

// Custom Constructor
Manager::Manager(string initialName, double initialSalary, string initialDepartment) : Employee(initialName, initialSalary)
{
	department = initialDepartment;
}

void Manager::printInfo()
{
	cout << getName() << ", $" << getSalary() << ", " << getDepartment() << endl;
}

string Manager::getDepartment() const
{
	return department;
}
