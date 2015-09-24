#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

// Finds the monthly paments for the loan
// @param amount - loan amount
// @param yearlyrate - yearly interest rate
// @param years - years for the loan
// @return - monthly pament
double getPayment(double amount, double yearlyRate, int years)
{
	double monthlyRate = (yearlyRate / 100.0) / 12;
	double numPayments = years * 12;
	double monthlyPayment = monthlyRate * pow(1 + monthlyRate, numPayments) / (pow(1 + monthlyRate, numPayments) - 1) * amount;
	
	return monthlyPayment;
}

// Takes the inputs from the user and passes the results by reference
// If the user enters NaN then they have to try again
// @param amount - loan amount
// @param rate - yearly interest rate
// @param years - years for the loan
// @return - none
void getUserInput(double& amount, double& rate, int& years)
{
	cout << "--------------------------------" << endl;
	cout << "Enter loan amount: $";
	cin >> amount;
	
	while(!cin)
	{
		cout << "Error! Please enter a number: $";
		cin.clear();
		cin.ignore();
		cin >> amount;
	}
	
	cout << "Enter interest rate as a percent: %";
	cin >> rate;
	
	while(!cin)
	{
		cout << "Error! Please enter a number: $";
		cin.clear();
		cin.ignore();
		cin >> rate;
	}
	
	cout << "Enter years (whole number): ";
	cin >> years;
	
	while(!cin)
	{
		cout << "Error! Please enter a number: $";
		cin.clear();
		cin.ignore();
		cin >> years;
	}
	
	// Fix negatives:
	amount = abs(amount);
	rate = abs(rate);
	years = abs(years);
}
	

int main()
{
	// Print initial info screen
	cout << "BRISEBOIS, GREGORY - CS116 FALL 2015" << endl;
	
	double loanAmount = 0;
	double yearlyRate = 0;
	int numYears = 0;
	bool repeat = false;
	
	// The main loop.  This happens as many times as the user wants.
	do
	{
		// Reset repeat.
		repeat = false;
		
		// Get inputs
		getUserInput(loanAmount, yearlyRate, numYears);
		
		// Process the inputs
		double payment = getPayment(loanAmount, yearlyRate, numYears);
		
		// Display the output
		cout << "--------------------------------" << endl;
		cout << "Amount: $" << loanAmount << endl;
		cout << "Yearly Rate: %" << yearlyRate << endl;
		cout << "Duration: " << numYears << " years" << endl;
		cout << "Monthly payments: $" << fixed << setprecision(2) << payment << endl;
		cout << "Total amount to be paid: $" << payment * 12 * numYears << endl;
		cout << "--------------------------------" << endl;
		
		// Figure out if the user wants to repeat
		char yn;
		cout << "Calculate another?  Enter Y or N: ";
		cin >> yn;
		yn = toupper(yn);
		repeat = (yn == 'Y');
		
	} while (repeat);
}
