/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/30 06:46:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>


#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define EXPECTED_ARG_COUNT	2
#define SEPARATORS			",;|"
#define DB_NAME				"data.csv"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class BitcoinExchange {

	private:

		// Attributes
			const char						*_fileName;
			std::ifstream					_file;
			std::ifstream					_database;
			std::map<std::string, float>	_dataMap;

		// Methods
			void initDataBase();
			void initFile(const int argCount, const char *fileName);
			void fillDate(const std::string line);
			void fillDatabase();
			void checkValueRequirements(const float value);
			void exchange(const std::string line);
			BitcoinExchange(); // Cannot be used

	public:

		// Constructors
			BitcoinExchange(const int argCount, const char *fileName);
			BitcoinExchange(const BitcoinExchange &bigcoinExchange);
		// Overload assignment operator
			BitcoinExchange &operator=(const BitcoinExchange &bigcoinExchange);
		// Member
			void displayConversion();
			void displayFile(std::ifstream &file);
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
			class InvalidDatabaseError: public std::exception {
				public:
					const char *what() const throw();
			};
			class NegativeValueError: public std::exception {
				public:
					const char *what() const throw();
			};
			class TooLargeValueError: public std::exception {
				public:
					const char *what() const throw();
			};
			class BadInputError: public std::exception {
				private:
					std::string _errorMessage;

				public:
					BadInputError(const std::string &message);
					const char *what() const throw();
					~BadInputError() throw();
			};
};