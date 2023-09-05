/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/30 09:08:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

#define EXPECTED_ARG_COUNT	2
#define DB_SEPARATORS		","
#define SEPARATORS			"|"
#define DB_NAME				"data.csv"

// Colors

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

// Error Messages

#define MISSING_ARG_ERROR_M		"could not open file."
#define TOO_MANY_ARG_ERROR_M	"too many given arguments."
#define INVALID_FILE_ERROR_M	"could not open file."
#define INVALID_DB_ERROR_M		"invalid database."
#define NEGATIVE_ERROR_M		"not a positive number."
#define TOO_LARGE_ERROR_M		"too large a number."
#define BAD_INPUT_ERROR_M		"bad input => "
#define INVALID_DATE_ERROR_M	"bad date format => "
#define TOO_EARLY_ERROR_M		"Bitcoin didn't exist at this time"

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
			void displayFile(std::ifstream &file) const;
			void checkDateFormat(const std::string &date) const;
			void checkValueRequirements(const float value) const;
			std::string findClosestDate(const std::map<std::string, float>& myMap, const std::string& input) const;
			void exchange(const std::string line) const;
			BitcoinExchange(); // Cannot be used

	public:

		// Constructors
			BitcoinExchange(const int argCount, const char *fileName);
			BitcoinExchange(const BitcoinExchange &bigcoinExchange);
		// Overload assignment operator
			BitcoinExchange &operator=(const BitcoinExchange &bigcoinExchange);
		// Member
			void displayConversion();
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
			class InvalidDateFormatError: public std::exception {
				private:
					std::string _errorMessage;

				public:
					InvalidDateFormatError(const std::string &message);
					const char *what() const throw();
					~InvalidDateFormatError() throw();
			};
			class TooEarlyDateError: public std::exception {
				public:
					const char *what() const throw();
			};
};