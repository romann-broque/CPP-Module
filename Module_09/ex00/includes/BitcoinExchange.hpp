/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/28 13:06:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define EXPECTED_ARG_COUNT 2

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class BitcoinExchange {

	public:

		// Constructors
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &bigcoinExchange);
		// Overload assignment operator
			BitcoinExchange &operator=(const BitcoinExchange &bigcoinExchange);
		// Member
			void displayFile(const std::string fileName) const;
			void checkFileArgument(const int argCount, char **arguments);
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
};