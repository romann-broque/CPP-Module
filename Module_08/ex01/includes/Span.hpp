/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:34:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:54:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class Span {

	private:

		size_t			_N;
		std::vector<long> _numbers;

	public:

		// Constructors
			Span();
			Span(const size_t N);
			Span(Span &span);
		// Overload assignment operator
			Span &operator=(Span &span);
		// Member functions
			void addNumber(const long nb);
			size_t shortestSpan(void);
			size_t longestSpan(void);
			void displaySpan(void);
		// Destructor
			~Span();
		// Exceptions
			class CantAddNumber: public std::exception {
				const char *what() const throw();
			};
			class ArrayTooSmall: public std::exception {
				const char *what() const throw();
			};
};