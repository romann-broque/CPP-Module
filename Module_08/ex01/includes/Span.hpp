/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:34:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 08:59:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[0;36m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class Span {

	private:

		// Attributes
			size_t				_N;
			std::vector<long>	_numbers;
		// Private member functions
			size_t getSpan(const long nb1, const long nb2);
			void checkInsertionParameters(const std::vector<long>::iterator pos, const size_t size);
			void addNumber(const std::vector<long>::iterator pos, const long nb);
			void addNumber(const std::vector<long>::iterator pos, const size_t size, const long nb);

	public:

		// Constructors
			Span();
			Span(const size_t N);
			Span(Span &span);
		// Overload assignment operator
			Span const &operator=(Span const &span);
		// Member functions
			void addNumber(const long nb);
			void insert(const std::vector<long>::iterator &begin, const long nb);
			void insertBySize(
					const std::vector<long>::iterator &begin,
					const size_t size,
					const long nb);
			void insertByRange(
					const std::vector<long>::iterator &begin,
					const long startNb,
					const long endNb);
			size_t shortestSpan(void);
			size_t longestSpan(void);
			std::vector<long>::iterator begin();
			std::vector<long>::iterator end();
			void display();
		// Destructor
			~Span();
		// Exceptions
			class CantAddNumber: public std::exception {
				const char *what() const throw();
			};
			class ArrayTooSmall: public std::exception {
				const char *what() const throw();
			};
			class InvalidIndex: public std::exception {
				const char *what() const throw();
			};
};