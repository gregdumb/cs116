#ifndef PERSON_H
#define PERSON_H

// Each wine has the following attributes:
// - Name
// - Vintage
// - Rating
// - Price
// - Wineary

class Wine
{
public:
	Wine(double price, std::string name);
	Wine(std::string newWineName, int newVintage, int newRating, double newPrice, std::string newWineary);
	Wine();
	
	// Mutators
	void setName(std::string newName);
	void setVintage(int newVintage);
	void setInfo(std::string newName, double newPrice, int newRating);
	
	// Accessors
	std::string getName();
	int getVintage();
	int getRating();
	double getPrice();
	std::string getWineary();
	
	
private:
	std::string name;
	int vintage;
	int rating;
	double price;
	std::string wineary;
};

#endif
