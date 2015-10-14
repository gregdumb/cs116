#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

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

// Sort functions used by the vector to sort itself
bool sortByPrice(Wine left, Wine right)
{
	return left.getPrice() < right.getPrice();
}
bool sortByRating(Wine left, Wine right)
{
	return left.getRating() > right.getRating();
}

void printAllWines(vector<Wine> wines, int ratingMin = 0, int ratingMax = 99, int priceMin = 0, int priceMax = 100)
{
	// Sort the wines
	sort(wines.begin(), wines.end(), sortByPrice); // @TODO &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& let user select sort type and bounds
	
	// Variables that control the formatting of output
	int nameWidth = 10;
	int vintageWidth = 10;
	int ratingWidth = 10;
	int priceWidth = 10;
	int winearyWidth = 10;
	int totalWidth = nameWidth + vintageWidth + ratingWidth + priceWidth + winearyWidth;
	
	// Make a bar to use for the ends
	string bar = "";
	bar.append(totalWidth + 4, '-');
	
	// Print column labels
	cout << bar << endl;
	cout << "| ";
	cout << setw(nameWidth) << left << "Name" 
	     << setw(vintageWidth) << "Vintage"
	     << setw(ratingWidth) << "Rating" 
	     << setw(priceWidth) << "Price" 
	     << setw(winearyWidth) << "Wineary" 
	     << " |" << endl;
	
	// This will keep track of how many wines make the cut
	int numSelectedWines = 0;
	
	// These will keep track of selected prices
	double totalPrice = 0;
	double avgPrice = 0;
	
	// Print the wine, if it makes the cut
	for(int i = 0; i < wines.size(); i++)
	{
		// IF rating and price are within set bounds
		if(wines[i].getRating() <= ratingMax && wines[i].getRating() >= ratingMin
		&& wines[i].getPrice() <= priceMax && wines[i].getPrice() >= priceMin)
		{		
		cout << "| ";
		cout << setw(nameWidth) << left << wines[i].getName()
		     << setw(vintageWidth) << wines[i].getVintage()
		     << setw(ratingWidth) << wines[i].getRating()
		     << "$" << setw(priceWidth-1) << fixed << setprecision(2) << wines[i].getPrice() // We have to subtract width by 1 to make space for the dollar sign
		     << setw(winearyWidth) << wines[i].getWineary()
		     << " |" << endl;
		    
		 // Update our selected wine statistics
		 numSelectedWines++;
		 totalPrice += wines[i].getPrice();
		 }
	}
	
	// Calculate the average
	avgPrice = totalPrice / numSelectedWines;
	
	// Print results
	cout << bar << endl;
	cout << "| " << "Total wines selected: " << numSelectedWines << endl;
	cout << "| " << "Average wine price: $" << avgPrice << endl;
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
