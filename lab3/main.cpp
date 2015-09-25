// Coded by Gregory Brisebois for CS116
// with instructor Ron Sha at Ohlone College
// Fall 2015 Semester, Lab 3, 

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// Course requirement - prints my own name on the console
void printMyName()
{
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

// Used to check that the age entered is valid.
// @param inAge - the value to verify
// @return - true if valid, false if invalid
bool verifyAge(int inAge)
{
	return inAge >= 0 && inAge <= 140;
}

// Prompts the user for their name and sanitizes the input
// @return - the name the user enters
string getUserName()
{
	cout << "Please enter your name: ";
	
	// This will be used to determine the validity of the entered name
	bool firstIsNum = false;
	
	// this will store the name until we can return it
	string tempName = "";
	
	do
	{
		cin.clear();
		cin >> tempName;
		
		// Check if the first letter is a number
		firstIsNum = isdigit(tempName.at(0));
		
		// if it is then we will need to loop around and try again
		if(firstIsNum)
		{
			cout << "The first letter in your name must not be a number!  Try again: ";
		}		
		
	} while (firstIsNum);
	
	return tempName;
}

// Prompts the user for their age and sanitizes the input
// @return - the age the user enters
int getUserAge()
{
	cout << "Please enter your age: ";
	
	// this will store the age until we can return it
	int tempAge = 0;
	
	do
	{
		// Clear the cin buffer first, in case we are in a loop
		cin.clear();
		cin.ignore(256, '\n');
		
		// Get the age
		cin >> tempAge;
		
		// Make sure it's a number
		if (cin.fail())
		{
			cout << "Please enter a number only!  Try again: ";
		}
		// Also make sure it's in the right range
		else if (!verifyAge(tempAge))
		{
			cout << "Error, your age was too high or too low!  Try again: ";
		}
	} while (!verifyAge(tempAge) || cin.fail());
	
	return tempAge;
}


int main()
{
	// Print my own name on the console (course requirement)
	printMyName();
	
	// This will be used to determine if the program will loop or exit
	bool doLoop = false;
	
	do
	{
		string userName = getUserName();
		int userAge = getUserAge();
		
		// Create class and get the values
		Person myPerson(userAge, userName);
		
		// Print out the results
		cout << endl << "The entered information has been stored as a class." << endl << endl;
		cout << myPerson.getName() << " is " << myPerson.getAge() << endl << endl;
		cout << "Enter Y to repeat the program: ";
		
		// Check to see if user wants to repeat
		string repeat = "";
		cin >> repeat;
		doLoop = (toupper(repeat[0]) == 'Y');
		
	} while (doLoop);
}
