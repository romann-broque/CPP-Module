/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/31 16:23:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

// Error Messages

#define MISSING_ARG_ERROR_M				"missing argument"
#define TOO_MANY_ARG_ERROR_M			"too many arguments"
#define INSUFFICIENT_OPERANDS_ERROR_M	"insufficient operands"
#define TOO_MANY_OPERANDS_ERROR_M		"too many operands"
#define UNEXPECTED_TOK_ERROR_M			"unexpected token"
#define DIVISION_BY_ZERO_ERROR_M		"division by zero"

// Colors

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define ASCII_NB_SHIFT		48
#define EXPECTED_ARG_COUNT	2
#define OPERATORS			"+-*/"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class RPN {

	private:

		// Attributes
			std::string _operationString;
		// Methods
			RPN(); // Cannot be used
			void processStack(std::stack<int> &operands) const;

	public:

		// Constructors
			RPN(const RPN &other);
			RPN(const int argCount, const char *operationString);
		// Overload assignment constructor
			RPN &operator=(const RPN &other);
		// Member
			void displayResult() const;
		// Destructor
			~RPN();
		// Exceptions
			class MissingArgumentError: public std::exception {
				public:
					const char *what() const throw();
			};
			class TooManyArgumentError: public std::exception {
				public :
					const char *what() const throw();
			};
			class InsufficientOperandsError: public std::exception {
				public :
					const char *what() const throw();
			};
			class TooManyOperandsError: public std::exception {
				public :
					const char *what() const throw();
			};
			class UnexpectedTokenError: public std::exception {
				public :
					const char *what() const throw();
			};
			class DivisionByZeroError: public std::exception {
				public :
					const char *what() const throw();
			};
};