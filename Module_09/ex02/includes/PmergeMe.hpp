/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 06:07:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/01 07:11:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>

// Error messages

#define MISSING_ARG_ERROR_M		"missing argument"
#define UNEXPECTED_CHAR_ERROR_M	"unexpected character"
#define OVERFLOW_ERROR_M		"overflow"
#define NEGATIVE_NB_ERROR_M		"negative number"

// Colors

#define NC		"\033[0m"
#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"

#define ASCII_NB_SHIFT	48

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

class PmergeMe {

	private:

		// Attributes
			std::vector<int>	_vectorSeq;
			std::list<int>		_listSeq;

	public:

		// Constructors
			PmergeMe();
			PmergeMe(char **sequence);
			PmergeMe(PmergeMe const &other);
		// Overload assignment operator
			PmergeMe &operator=(PmergeMe const &other);
		// Destructor
			~PmergeMe();
		// Exceptions
			class MissingArgError: public std::exception {
				public:
					const char *what() const throw();
			};
			class UnexpectedCharacterError: public std::exception {
				public:
					const char *what() const throw();
			};
			class OverflowError: public std::exception {
				public:
					const char *what() const throw();
			};
			class NegativeNumberError: public std::exception {
				public:
					const char *what() const throw();
			};
};