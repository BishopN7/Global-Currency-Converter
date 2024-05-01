#include "GlobalCurrencyConverter.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Constructor for the currency class
Currency::Currency(const std::string& code, const std::string& name) : code(code), name(name) {}

// Accessor method for currency code
std::string Currency::getCode() const {
	return code;
}

// Accessor method for currency name
std::string Currency::getName() const {
	return name;
}

int main() {
	// Main variables for the conversion
	double exchangeRate, convertedBalance;
	int initialAmount;
	string fromCurrency, toCurrency;

	// Vector for storing currencies
	std::vector<Currency> currencies = {
		Currency("USD", "US Dollar"),
		Currency("EUR", "Euro"),
		Currency("JPY", "Japanese Yen"),
		Currency("GBP", "Pounds Sterling"),
		Currency("CNY", "Chinese Yuan"),
		Currency("CAD", "Canadian Dollar"),
		Currency("AUD/NZD", "Australian/New Zealand Dollar"),
		Currency("ZAR", "South African Rand"),
		Currency("CHF", "Swiss Franc"),
		Currency("CNH", "Chinese Yuan Offshore"),
		Currency("HKD", "Hong Kong Dollar")

	};

	// Display a welcome message to the user
	std::cout << "*****************************************" << '\n';
	std::cout << "Welcome to the Global Currency Converter!" << '\n';
	std::cout << "*****************************************" << '\n';

	// Instance for the GlobalCurrencyConverterClass
	GlobalCurrencyConverter converter;

	// User-menu for picking which currency to convert from
	std::cout << "Please pick which currency you would like to convert from (e.g., USD): " << '\n';
	for (int i = 0; i < currencies.size(); ++i) {
		std::cout << i + 1 << ". " << currencies[i].getName() << '\n';
	}
	std::cin >> fromCurrency;

	// User-menu for the picking which currency to convert to
	std::cout << "Please pick which currency you would like to convert to (e.g., EUR): " << '\n';
	for (int i = 0; i < currencies.size(); ++i) {
		std::cout << i + 1 << ". " << currencies[i].getName() << '\n';
	}
	std::cin >> toCurrency;

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
	} while (initialAmount < 0);

	// Obtain user-input for the exchange rate
	do {
		std::cout << "Please enter the exchange rate: " << '\n';
		std::cin >> exchangeRate;

		// Conditional if the user makes an error 
		if (exchangeRate < 0) {
			std::cout << "Error! Please enter a value that is non-negative." << '\n';
		}
		else {
			validInput = true;
		}
	} while (exchangeRate < 0);

	// Perform the calculation for the conversion
	convertedBalance = initialAmount * exchangeRate;

	// Display for showing the conversion
	std::cout << std::fixed << setprecision(2);
	std::cout << '\n' << "------------------------------" << '\n';
	std::cout << '\n' << "Live Converted Current Balance" << '\n';
	std::cout << '\n' << "------------------------------" << '\n';
	std::cout << '\n' << "                              " << '\n';
	std::cout << '\n' << std::setw(25) << "Original Balance: " << initialAmount << " " << fromCurrency << '\n';
	std::cout << std::setw(25) << "Converted Balance: " << convertedBalance << " " << toCurrency << '\n';

	// Prompt the user if they want to do another conversion
	char choice;
	std::cout << "Would you like to make another conversion? (y/n)" << '\n';
	std::cin >> choice;

	switch (choice) {
	case 'y':
	case 'Y':
			main();
			break;
	case 'n':
	case 'N':
		  // Display a thank message if either of the options are chosen
		  std::cout << "Thank you for using the global currency converter! Have a blessed day." << '\n';
	default:
		  std::cout << "Error! Please pick either between (y or n)" << '\n';
	}

	return 0;

}
