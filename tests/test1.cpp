#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct Employee {
		string name;
		int age;
		double salary;
	};
	
	Employee Greg;
	Greg.name = "Greg";
	Greg.age = 19;
	Greg.salary = 10.6;
	
	cout << Greg.name << " is " << Greg.age << ", and gets paid $" << Greg.salary << endl;
}
