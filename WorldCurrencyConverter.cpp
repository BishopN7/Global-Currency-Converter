#include "global_currency_converter.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	// Main variables for the conversion
	double exchangeRate, convertedBalance;
	int initialAmount;
	string currencies;

	// Vector for storing currencies
	std::vector<std::string> currencies = { "USD", "EUR", "JPY", "GBP", "CNY", "CAD", "AUD/NZD", "ZAR", "CHF", "CNH", "HKD"};

	// Display a welcome message to the user
	std::cout << "********************************************" << '\n';
	std::cout << "Welcome to the Global Currency Converter!" << '\n';
	std::cout << "********************************************" << '\n';

	// User-menu for picking which currency to convert to
	std::cout << "Please pick currency you would like to convert to: " << '\n';
	for (int i = 0; i < currencies.size(); ++i) {
		std::cout << i + 1 << ". " << currencies[i] << '\n';
	}

	// Initial investment do-while loop
	bool validInput = false;

	do {

		std::cout << "Please enter your initial investment: " << '\n';
		std::cin >> initialAmount;

		// Conditional if the user makes an error
		if (initialAmount < 0) {
			std::cout << "Error! Please enter a non-negative value." << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Exchange Rate do-while loop
	bool validInput = false;

	do {
		std::cout << "Please enter the exchange rate of the country you're traveling to (in decimals): " << '\n';
		std::cin >> exchangeRate;

		// Conditional if the user makes an error 
		if (exchangeRate < 0) {
			std::cout << "Error! Please enter a value that is non-negative." << '\n';
		}
		else {
			validInput = true;
		}
	} while (!validInput);

	// Display for showing the conversion
	std::cout << std::fixed << setprecision(2);
	std::cout << '\n' << "------------------------------" << '\n';
	std::cout << '\n' << "Live Converted Current Balance" << '\n';
	std::cout << '\n' << "------------------------------" << '\n';
	std::cout << '\n' << "                              " << '\n';
	std::cout << "  " << std::setw(5) << "Original Balance" << std::setw(27) << "Converted Balance" << '\n';

	// Calculate and convert the original balance
	double convertedBalance = initialAmount * exchangeRate;

	// Display the updated conversion
	

	// Prompt the user if they want to do another conversion
	char choice;
	std::cout << "Would you like to make another conversion? (y/n)" << '\n';
	std::cin >> choice;

	switch (choice) {
	case 'y':
	case 'Y';
		main();
		break;
	case 'n';
	case 'N';
		// Display a thank message if either of the options are chosen
		std::cout << "Thank you for using the worldwide currency converter! Have a blessed day." << '\n';
	default:
		std::cout << "Error! Please pick either between (y or n)" << '\n';
	}

	return 0;

}

