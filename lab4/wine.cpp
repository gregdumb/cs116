#include <string>
#include "wine.h"

// Constructors

Wine::Wine()
{
	name = "newwine";
	vintage = 0;
	rating = 0;
	price = 0.00;
	wineary = "newwineary";
}

Wine::Wine(std::string newWineName, int newVintage, int newRating, double newPrice, std::string newWineary)
{
	name = newWineName;
	vintage = newVintage;
	rating = newRating;
	price = newPrice;
	wineary = newWineary;
}

// Mutators

// Change the name
void Wine::setName(std::string newName)
{
	name = newName;
}

// Change the vintage
void Wine::setVintage(int newVintage)
{
	vintage = newVintage;
}

// Change name, price, and rating all at once
void Wine::setInfo(std::string newName, double newPrice, int newRating)
{
	name = newName;
	price = newPrice;
	rating = newRating;
}

// Accessors

// get the name
std::string Wine::getName()
{
	return name;
}

// get the vintage
int Wine::getVintage()
{
	return vintage;
}

// get the rating
int Wine::getRating()
{
	return rating;
}

// get the price
double Wine::getPrice()
{
	return price;
}

// get the wineary
std::string Wine::getWineary()
{
	return wineary;
}

