class Executive : public Manager
{
	public:
	// Constructors
	Executive();
	Executive(string initialName, double initialSalary, string initialDepartment);
	
	void printInfo();
};

Executive::Executive() : Manager()
{
};

Executive::Executive(string initialName, double initialSalary, string initialDepartment) : Manager(initialName, initialSalary, initialDepartment)
{
};

void Executive::printInfo()
{
	cout << "Executive" << endl;
	Manager::printInfo();
}
