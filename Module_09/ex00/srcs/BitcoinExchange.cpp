/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/28 13:04:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors

BitcoinExchange::BitcoinExchange() {
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

void BitcoinExchange::displayFile(const std::string fileName) const {
	std::cout << "The file is " << fileName << std::endl;
}

void BitcoinExchange::checkFileArgument(const int argCount, char **arguments) {

	if (argCount < EXPECTED_ARG_COUNT)
		throw BitcoinExchange::MissingArgumentError();
	if (argCount > EXPECTED_ARG_COUNT)
		throw BitcoinExchange::TooManyArgumentError();
	(void)arguments;
}

// Destructor

BitcoinExchange::~BitcoinExchange() {
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