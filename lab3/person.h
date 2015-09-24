#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
public:
	std::string teststring;
	
	int getAge();
	
private:
	std::string name;
	int age;
};



#endif
