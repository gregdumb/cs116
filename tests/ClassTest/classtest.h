class testClass
{
public:
	int testInt;
	
	void printHello();
	
	testClass()
	{
		testInt = 5;
	};
	
	testClass(int i)
	{
		testInt = i;
	};
};

class newClass : public testClass(33)
{
	public:
	newClass()
	{
		//testInt = 10;
	};
};
