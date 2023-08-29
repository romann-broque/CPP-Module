/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/29 07:48:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors

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

// Overload assignment operator

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
	(void)bitcoinExchange;
	return *this;
}

// Member

void BitcoinExchange::displayConversion(void) {
	std::string line;
	while (std::getline(_file, line)) {
		initConversion(line);
	}
	displayFile(_database);
}

void BitcoinExchange::displayFile(std::ifstream &file) {
	
	std::string	line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
}

// Destructor

BitcoinExchange::~BitcoinExchange() {

	_file.close();
	_database.close();
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

void BitcoinExchange::initDataBase() {

	std::ifstream file(DB_NAME);
	if (!file.is_open()) {
		throw BitcoinExchange::InvalidFileError();
	}
	file.close();
	_database.open(DB_NAME);
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

void BitcoinExchange::initConversion(const std::string line) {

	(void)line;	
	// std::string lineWithoutSpaces = removeWhiteSpaces(line);

	// std::size_t separatorPos = line.find_first_of(SEPARATORS);
	// if (separatorPos != std::string::npos) {
	// 	std::string datePart = line.substr(0, separatorPos);
	// 	std::string valuePart = line.substr(separatorPos + 1);

	// 	std::istringstream valueStream(valuePart);
	// 	float value;
	// 	if (valueStream >> value) {
	// 		_dateList.push_back(datePart);
	// 		_valueList.push_back(value);
	// 		_resultList.push_back(value * );
	// 		return;
	// 	}
	// }
	// else {
	// 	_errorList.push_back("Error: bad input => " + line);
	// 	_dateList.push_back(line); // Assuming the whole line is the date
	// 	_valueList.push_back(std::numeric_limits<float>::quiet_NaN());
	// }
}
