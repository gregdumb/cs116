#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{/
	private:
	int hiddenint;
	
	public:
	int firstint;
	int secondint;
	
	Employee()
	{
		firstint = 10;
		secondint = 20;
		hiddenint = 45;
	}
	
	Employee(int replacer)
	{
		firstint = replacer;
		secondint = 20;
		hiddenint = 45;
	}
	
	int gethidden();
	void printhidden();
};


#endif
