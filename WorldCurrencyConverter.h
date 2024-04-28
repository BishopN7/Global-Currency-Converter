#ifndef WORLD_CURRENCY_CONVERTER_H
#define WORLD_CURRENCY_CONVERTER_H

// Class for world currencies
class Currency {
public:
	// Constructor for the currency class
	Currency(const std::string& code, const std::string& name);

	// Acessor methods for curremcy code and names
	std::string getCode() const;
	std::string getName() const;

private:
	// Private member variables for the currency class
	std::string code;
	std::string name;
};

// The primary class for currency conversion
class WorldCurrencyConverter {
public:
	// Function to convert from one currency to another
	double convert(double amount, const std::string& from_currency, const std::string& to_currency) const;

	// (Optional) function to obtain live world exchange rates
	void updateExchangeRates();

private:
	// Function to store exchange rates 
	std::map<std::string, std::map<std::string, double>> exchange_rates_;
};

#endif