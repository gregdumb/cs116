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

// Prompts the user to enter 1 wine
// @return the created wine class
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

// Prints a list of all wines, with the options to sort or display only those in a certain range
// @param wines - the vector of wines to display
// @param ratingMin - the minimum rating to include in the display
// @param ratingMax - max rating to include
// @param minPrice, maxPrice - min and max prices to include
void printAllWines(vector<Wine> wines, int ratingMin = 0, int ratingMax = 99, int priceMin = 0, int priceMax = 100, char sortId = 0)
{
	// String that will tell the user how we sorted
	string sortTypeDisplay = "Not sorted";
	
	// Sort (or not) based on the input
	switch(sortId)
	{
		case 'r':
			sort(wines.begin(), wines.end(), sortByRating);
			sortTypeDisplay = "Sorted by rating";
			break;
		
		case 'p':
			sort(wines.begin(), wines.end(), sortByPrice);
			sortTypeDisplay = "Sorted by price";
			break;
	}
	
	// Variables that control the width of the output columns
	int nameWidth = 10;
	int vintageWidth = 10;
	int ratingWidth = 10;
	int priceWidth = 10;
	int winearyWidth = 10;
	int totalWidth = nameWidth + vintageWidth + ratingWidth + priceWidth + winearyWidth;
	
	// Make a bar to use for the ends (formatting)
	string bar = "|";
	bar.append(totalWidth + 2, '-');
	bar.append("|");
	
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
			// Print out the row for the wine
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
	
	// Calculate the average price
	avgPrice = totalPrice / numSelectedWines;
	
	// Print summary of results after the chart
	cout << bar << endl;
	cout << "| " << "Total wines selected: " << numSelectedWines << endl;
	cout << "| " << "Average wine price: $" << avgPrice << endl;
	cout << "| " << sortTypeDisplay << endl;
	cout << bar << endl;
}

int main()
{
	printMyName();
	
	cout << endl << "-- Enter Wines --" << endl;
	
	// This is our main vector of wines
	vector<Wine> wineVect;
	
	// loop that allows user to enter new wines until breaking out by not entering 'y' at the prompt
	bool doloop = false;
	do
	{
		// Create the new wine
		Wine myWine = getWineInput();
		
		// Add it to the vector
		wineVect.push_back(myWine);
		
		// Ask if we want to enter another
		cout << "Enter another wine? y,n: " << endl;
		char cont;
		cin >> cont;
		doloop = (cont == 'y');
	}
	while (doloop);
	
	// Now we want to know the range of price and rating that the user wants to display
	int minRating = 0, maxRating = 100, minPrice = 0, maxPrice = 1000;
	cout << endl << "-- Display Options --" << endl;
	cout << "Enter min desired rating: "; cin >> minRating;
	cout << "Enter max desired rating: "; cin >> maxRating;
	cout << "Enter min desired price: "; cin >> minPrice;
	cout << "Enter max desired price: "; cin >> maxPrice;
	
	// Prompt for sort type
	char sortId = 0; // r = rating, p = price, other = none
	cout << "How do you want to sort? r = rating, p = price, n = none: ";
	cin >> sortId;
	
	cout << endl << "-- Results --" << endl;
	
	// Display the wines
	printAllWines(wineVect, minRating, maxRating, minPrice, maxPrice, sortId);
}
