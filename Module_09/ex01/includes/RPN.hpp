/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/30 09:29:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>

// Error Messages

#define MISSING_ARG_ERROR_M		"missing argument"
#define TOO_MANY_ARG_ERROR_M	"too many arguments"

// Colors

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define EXPECTED_ARG_COUNT	2

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class RPN {

	private:

		// Attributes
			std::string _operationString;

	public:

		// Constructors
			RPN();
			RPN(const RPN &other);
			RPN(const int argCount, const char *operationString);
		// Overload assignment constructor
			RPN &operator=(const RPN &other);
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

};