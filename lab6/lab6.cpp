#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Course requirement - prints my own name on the console
void printMyName()
{
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

string getFilename()
{
	string inFilename = "";
	cout << "Please enter the name of the file: ";
	cin >> inFilename;
	return inFilename;
}

bool fileExists(string filename)
{
	ifstream file(filename);
	return true;
}

int main()
{
	printMyName();
	
	string filename = getFilename();
	
	if(fileExists(filename))
	{
		cout << "File Exists!" << endl;
	}
	else
	{
		cout << "File does not exist!" << endl;
	}
}