#include <iostream>
#include <string>

using namespace std;

#include "employee.h"
#include "manager.h"
#include "executive.h"

// Course requirement - prints my own name on the console
void printMyName()
{
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

int main()
{
	printMyName();
	
	Executive myExec("Tyler", 60000, "Rides Dept");
	
	myExec.printInfo();
}























