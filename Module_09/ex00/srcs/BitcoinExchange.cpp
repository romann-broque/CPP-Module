/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/22 16:49:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

////////////////////
// Static methods //
////////////////////

static void	resetFile(std::ifstream &file) {

	file.clear();
	file.seekg(0);
}

static std::string removeWhiteSpaces(const std::string str) {

	std::string	newStr;

	for (size_t i = 0; i < str.size(); ++i) {
		if (!std::isspace(str[i])) {
			newStr += str[i];
		}
	}
	return newStr;
}

static bool isValidDateFormat(const std::string& date) {

	// Check the format: YYYY-MM-DD
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	// Check if each character is a digit
	for (int i = 0; i < 10; ++i) {
		if (i != 4 && i != 7 && !isdigit(date[i])) {
			return false;
		}
	}
	return true;
}

//////////////////
// Constructors //
//////////////////

// Cannot be used
BitcoinExchange::BitcoinExchange() {

	initDataBase();
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		GREEN << "created (empty)" << NC << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const int argCount, const char *filename) {

	initDataBase();
	initFile(argCount, filename);
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) {

	*this = bitcoinExchange;
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

//////////////////////////////////
// Overload assignment operator //
//////////////////////////////////

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
	(void)bitcoinExchange;
	return *this;
}

////////////
// Member //
////////////

void BitcoinExchange::displayConversion(void) {
	std::string line;

	while (std::getline(_file, line)) {
		try {
			exchange(line);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

////////////////
// Destructor //
////////////////

BitcoinExchange::~BitcoinExchange() {

	_file.close();
	_database.close();
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		RED << "destroyed" << std::endl;
	}
}

////////////////
// Exceptions //
////////////////

const char *BitcoinExchange::MissingArgumentError::what() const throw() {
	return MISSING_ARG_ERROR_M;
}

const char *BitcoinExchange::TooManyArgumentError::what() const throw() {
	return TOO_MANY_ARG_ERROR_M;
}

const char *BitcoinExchange::InvalidFileError::what() const throw() {
	return INVALID_FILE_ERROR_M;
}

const char *BitcoinExchange::InvalidDatabaseError::what() const throw() {
	return INVALID_DB_ERROR_M;
}

const char *BitcoinExchange::NegativeValueError::what() const throw() {
	return NEGATIVE_ERROR_M;
}

const char *BitcoinExchange::TooLargeValueError::what() const throw() {
	return TOO_LARGE_ERROR_M;
}

BitcoinExchange::BadInputError::BadInputError(const std::string &message) {
	_errorMessage = BAD_INPUT_ERROR_M + message;
}

BitcoinExchange::BadInputError::~BadInputError() throw() {}

const char *BitcoinExchange::BadInputError::what() const throw() {
	return _errorMessage.c_str();
}

BitcoinExchange::InvalidDateFormatError::InvalidDateFormatError(const std::string &message) {
	_errorMessage = INVALID_DATE_ERROR_M + message;
}

BitcoinExchange::InvalidDateFormatError::~InvalidDateFormatError() throw() {}

const char *BitcoinExchange::InvalidDateFormatError::what() const throw() {
	return _errorMessage.c_str();
}

const char *BitcoinExchange::TooEarlyDateError::what() const throw() {
	return TOO_EARLY_ERROR_M;
}

/////////////////////
// Private methods //
/////////////////////

// Init Methods //

void BitcoinExchange::initDataBase() {

	std::ifstream file(DB_NAME);
	if (!file.is_open()) {
		throw BitcoinExchange::InvalidDatabaseError();
	}
	file.close();
	_database.open(DB_NAME);
	fillDatabase();
}

void BitcoinExchange::initFile(const int argCount, const char *fileName) {

	if (argCount < EXPECTED_ARG_COUNT)
		throw BitcoinExchange::MissingArgumentError();
	if (argCount > EXPECTED_ARG_COUNT)
		throw BitcoinExchange::TooManyArgumentError();
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw BitcoinExchange::InvalidFileError();
	}
	file.close();
	_fileName = fileName;
	_file.open(fileName);
}

// Fill Methods //

void BitcoinExchange::fillDate(const std::string line) {

	std::string lineWithoutSpaces = removeWhiteSpaces(line);
	std::size_t separatorPos = line.find_first_of(DB_SEPARATORS);

	if (separatorPos != std::string::npos) {
		std::string datePart = lineWithoutSpaces.substr(0, separatorPos);
		std::string valuePart = lineWithoutSpaces.substr(separatorPos + 1);

		std::istringstream valueStream(valuePart);
		float value;
		if (valueStream >> value) {
			checkDateFormat(datePart);
			_dataMap[datePart] = value;
			return;
		}
	}
	else {throw InvalidDatabaseError();}
}

void BitcoinExchange::fillDatabase() {

	std::string	line;

	while (std::getline(_database, line)) {
		fillDate(line);
	}
	resetFile(_database);
}

void BitcoinExchange::displayFile(std::ifstream &file) const {

	std::string	line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	resetFile(file);
}

void BitcoinExchange::checkDateFormat(const std::string &date) const {

	if (!isValidDateFormat(date))
		throw InvalidDateFormatError(date);
}

void BitcoinExchange::checkValueRequirements(const float value) const {
	if (value < 0)
		throw NegativeValueError();
	if (value > 1000)
		throw TooLargeValueError();
}

std::string	BitcoinExchange::findClosestKey(const std::map<std::string, float>& myMap, const std::string& inputKey) const {

	std::map<std::string, float>::const_iterator closestKey = myMap.upper_bound(inputKey);
	if (closestKey == myMap.begin())
		throw TooEarlyDateError();
	return (--closestKey)->first;
}

std::string BitcoinExchange::findClosestDate(const std::map<std::string, float>& myMap, const std::string& input) const {
	std::string closestDate = findClosestKey(myMap, input);

	return closestDate;
}

void BitcoinExchange::exchange(const std::string line) const {

	std::string lineWithoutSpaces = removeWhiteSpaces(line);
	std::size_t separatorPos = lineWithoutSpaces.find_first_of(SEPARATORS);

	if (separatorPos != std::string::npos) {
		std::string datePart = lineWithoutSpaces.substr(0, separatorPos);
		std::string valuePart = lineWithoutSpaces.substr(separatorPos + 1);

		std::istringstream valueStream(valuePart);
		float value;
		if (valueStream >> value) {
			checkDateFormat(datePart);
			checkValueRequirements(value);
			std::string closestDate = findClosestDate(_dataMap, datePart);
			std::cout << closestDate << " => " << value
				<< " = " << value * _dataMap.at(closestDate) << std::endl;
		}
	} else {throw BadInputError(line);}
}
