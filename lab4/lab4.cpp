#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "wine.h"

using namespace std;

// Course requirement - prints my own name on the console
void printMyName()
{
	cout << "MADE BY GREGORY BRISEBOIS" << endl;
	cout << "CS116 OHLONE COLLEGE" << endl;
	cout << "-------------------------" << endl;
}

Wine getWineInput()
{
	string newName = "";
	int newVintage = 0;
	int newRating = 0;
	double newPrice = 0;
	string newWineary = "";
	
	cout << "Enter wine name: ";
	cin >> newName;
	
	cout << "Enter vintage: ";
	cin >> newVintage;
	
	cout << "Enter rating (0 - 100): ";
	cin >> newRating;
	
	cout << "Enter price: $";
	cin >> newPrice;
	
	cout << "Enter wineary: ";
	cin >> newWineary;
	
	Wine newWine(newName, newVintage, newRating, newPrice, newWineary);
	
	return newWine;
}

void printAllWines(vector<Wine> wines)
{
	int nameWidth = 10;
	int vintageWidth = 10;
	int ratingWidth = 10;
	int priceWidth = 10;
	int winearyWidth = 10;
	int totalWidth = nameWidth + vintageWidth + ratingWidth + priceWidth + winearyWidth;
	
	// Make a bar to use for the ends
	string bar = "";
	bar.append(totalWidth + 4, '-');
		
	cout << bar << endl;
	
	cout << "| ";
	cout << setw(nameWidth) << left << "Name" 
	     << setw(vintageWidth) << "Vintage"
	     << setw(ratingWidth) << "Rating" 
	     << setw(priceWidth) << "Price" 
	     << setw(winearyWidth) << "Wineary" 
	     << " |" << endl;
	
	for(int i = 0; i < wines.size(); i++)
	{
		cout << "| ";
		cout << setw(nameWidth) << left << wines[i].getName()
		     << setw(vintageWidth) << wines[i].getVintage()
		     << setw(ratingWidth) << wines[i].getRating()
		     << setw(priceWidth) << wines[i].getPrice()
		     << setw(winearyWidth) << wines[i].getWineary()
		     << " |" << endl;
	}
	
	cout << bar << endl;
}

int main()
{
	printMyName();
	
	// Wine myWine = getWineInput();
	
	//vector<Wine> wineVect;
	
	//wineVect.push_back(myWine);
	
	vector<Wine> wineVect;
	
	bool doloop = false;
	do
	{
		Wine myWine = getWineInput();
	
		
		
		wineVect.push_back(myWine);
		
		cout << "Enter another wine? y,n: " << endl;
		char cont;
		cin >> cont;
		doloop = (cont == 'y');
	}
	while (doloop);
	
	printAllWines(wineVect);
	
	/*cout << "The wine you entered:" << endl;
	cout << myWine.getName() << endl;
	cout << myWine.getVintage() << endl;
	cout << myWine.getRating() << endl;
	cout << myWine.getPrice() << endl;
	cout << myWine.getWineary() << endl;*/
}
