#include <iostream>
#include <string>

using namespace std;

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
	
	string name;
	
	cout << endl << "Please enter your name: ";
	
	cin >> name;
}
