#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
public:
	// Accessor functions
	int getAge();
	std::string getName();
	
	// Mutator functions
	void setAge(int);
	void setName(std::string);
	
	// Constructors
	Person();
	Person(int, std::string);
	
private:
	std::string name;
	int age;
};

// Constructor 1
Person::Person()
{
	age = 0;
	name = "Noname";
}

// Constructor 2
Person::Person(int inage, std::string inname)
{
	age = inage;
	name = inname;
}

// Accessors

int Person::getAge()
{
	return age;
}

std::string Person::getName()
{
	return name;
}

// Mutators

void Person::setAge(int newage)
{
	age = newage;
}

void Person::setName(std::string newname)
{
	name = newname;
}

#endif
