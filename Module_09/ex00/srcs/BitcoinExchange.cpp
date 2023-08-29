/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/29 08:33:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Static methods

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

	std::cout << "This is " << _fileName << std::endl;
	while (std::getline(_file, line)) {
		try {
			exchange(line);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::displayFile(std::ifstream &file) {
	
	std::string	line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	resetFile(file);
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

const char *BitcoinExchange::InvalidDatabaseError::what() const throw() {
	return "Invalid Database";
}

BitcoinExchange::BadInputError::BadInputError(const std::string &message) {
	_errorMessage = "bad input => " + message;
}

BitcoinExchange::BadInputError::~BadInputError() throw() {}

const char *BitcoinExchange::BadInputError::what() const throw() {
	return _errorMessage.c_str();
}

// Private methods

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

void BitcoinExchange::fillDate(const std::string line) {
	
	std::string lineWithoutSpaces = removeWhiteSpaces(line);
	std::size_t separatorPos = line.find_first_of(SEPARATORS);

	if (separatorPos != std::string::npos) {
		std::string datePart = line.substr(0, separatorPos);
		std::string valuePart = line.substr(separatorPos + 1);

		std::istringstream valueStream(valuePart);
		float value;
		if (valueStream >> value) {
			_dataMap[datePart] = value;
			return;
		}
	}
	else {throw InvalidDatabaseError();}
}

void BitcoinExchange::exchange(const std::string line) {
	
	std::string lineWithoutSpaces = removeWhiteSpaces(line);
	std::size_t separatorPos = line.find_first_of(SEPARATORS);

	if (separatorPos != std::string::npos) {
		std::string datePart = line.substr(0, separatorPos);
		std::string valuePart = line.substr(separatorPos + 1);

		std::istringstream valueStream(valuePart);
		float value;
		if (valueStream >> value) {
			std::cout << datePart << " => " << value << " = " << value * _dataMap[datePart] << std::endl;
			return;
		}
	}
	else {throw BadInputError(line);}
}

void BitcoinExchange::fillDatabase() {

	std::string	line;

	while (std::getline(_database, line)) {
		fillDate(line);
	}
	resetFile(_database);
}
