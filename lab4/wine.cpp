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

// Mutators
void Wine::setName(std::string newName)
{
	name = newName;
}

void Wine::setVintage(int newVintage)
{
	vintage = newVintage;
}

void Wine::setInfo(std::string newName, double newPrice, int newRating)
{
	name = newName;
	price = newPrice;
	rating = newRating;
}

// Accessors
std::string Wine::getName()
{
	return name;
}

int Wine::getVintage()
{
	return vintage;
}

int Wine::getRating()
{
	return rating;
}

double Wine::getPrice()
{
	return price;
}

std::string Wine::getWineary()
{
	return wineary;
}

