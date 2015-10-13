#include <iostream>
#include "classtest.h"

using namespace std;

int main()
{
	testClass *myClass = new testClass;
	
	if(myClass)
		myClass->printHello();
	else
		cout << "it is NULL" << endl;
		
	cout << &myClass << endl;
}
