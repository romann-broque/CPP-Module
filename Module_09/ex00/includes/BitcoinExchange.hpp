/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/29 07:21:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <limits>
#include <cmath>

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define EXPECTED_ARG_COUNT	2
#define SEPARATORS			",;|"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class BitcoinExchange {

	private:

		// Attributes
			std::ifstream			_file;
			const char				*_fileName;
			std::list<std::string>	_dateList;
			std::list<float>		_valueList;	
			std::list<double>		_resultList;	
			std::list<std::string>	_errorList;	
		// Methods
			void initFile(const int argCount, const char *fileName);
			void initConversion(std::string line);
			BitcoinExchange(); // Cannot be used

	public:

		// Constructors
			BitcoinExchange(const int argCount, const char *fileName);
			BitcoinExchange(const BitcoinExchange &bigcoinExchange);
		// Overload assignment operator
			BitcoinExchange &operator=(const BitcoinExchange &bigcoinExchange);
		// Member
			void displayFile(void);
			void displayConversion(void);
		// Destructor
			~BitcoinExchange();
		// Exceptions
			class MissingArgumentError: public std::exception {
				public:
					const char *what() const throw();
			};
			class TooManyArgumentError: public std::exception {
				public:
					const char *what() const throw();
			};
			class InvalidFileError: public std::exception {
				public:
					const char *what() const throw();
			};
};