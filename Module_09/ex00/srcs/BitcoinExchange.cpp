/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/29 07:22:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors

// Cannot be used
BitcoinExchange::BitcoinExchange() {
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		GREEN << "created (empty)" << NC << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const int argCount, const char *filename) {

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

// Overload assignment operator

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
	(void)bitcoinExchange;
	return *this;
}

// Member

void BitcoinExchange::displayFile(void) {
	std::string line;
	while (std::getline(_file, line)) {
		initConversion(line);
	}
	displayConversion();
}

void BitcoinExchange::displayConversion(void) {

	std::list<std::string>::iterator itDate = _dateList.begin();
	std::list<float>::iterator itValue = _valueList.begin();
	// std::list<double>::iterator itResult = _resultList.begin();
	std::list<std::string>::iterator itError = _errorList.begin();
	for (; itDate != _dateList.end(); ++itDate, ++itValue){
		// , ++itResult) {
		
		if (std::isnan(*itValue)){
			std::cout << *itError;
			++itError;
		} else {
			std::cout << *itDate << " => " << *itValue << " = ";// << *itResult;
		}
		std::cout << std::endl;
	}
}

// Destructor

BitcoinExchange::~BitcoinExchange() {

	_file.close();
	if (PRINT_DEBUG) {
		std::cout << "BitcoinExchange has been " <<
		RED << "destroyed" << std::endl;
	}
}

// Exceptions

const char *BitcoinExchange::MissingArgumentError::what() const throw() {
	return "File name is missing";
}

const char *BitcoinExchange::TooManyArgumentError::what() const throw() {
	return "Too many given arguments";
}

const char *BitcoinExchange::InvalidFileError::what() const throw() {
	return "Invalid File";
}

// Private methods

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

static std::string removeWhiteSpaces(std::string line) {

	std::string str;

	for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
		if (!std::isspace(*it))
			str += *it;
	}
	return str;
}

void BitcoinExchange::initConversion(const std::string line) {
	
	std::string lineWithoutSpaces = removeWhiteSpaces(line);

	std::size_t separatorPos = line.find_first_of(SEPARATORS);
	if (separatorPos != std::string::npos) {
		std::string datePart = line.substr(0, separatorPos);
		std::string valuePart = line.substr(separatorPos + 1);

		std::istringstream valueStream(valuePart);
		float value;
		if (valueStream >> value) {
			_dateList.push_back(datePart);
			_valueList.push_back(value);
			return;
		}
	}
	else {
		_errorList.push_back("Error: bad input => " + line);
		_dateList.push_back(line); // Assuming the whole line is the date
		_valueList.push_back(std::numeric_limits<float>::quiet_NaN());
	}
}
