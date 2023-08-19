/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:34:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:00:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class Span {

	private:

		size_t	_N;
		size_t	_setValue;
		long	*_numbers;

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
};