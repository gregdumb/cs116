#include <iostream>
#include <string>

#include "wine.h"

using namespace std;

int main()
{
	Wine myWine;
	
	myWine.setName("Scotch");
	
	cout << myWine.getName() << endl;
	cout << myWine.getWineary() << endl;
}
