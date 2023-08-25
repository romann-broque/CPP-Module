/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:37:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/25 14:50:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors

Span::Span(): _N(0) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		GREEN << "created" << NC << std::endl;
	}
}

Span::Span(const size_t N): _N(N) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		GREEN << "created" << NC << std::endl;
	}
}

Span::Span(Span &span) {

	*this = span;
	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

Span const &Span::operator=(Span const &span) {

	if (this != &span) {
		_N = span._N;
		_numbers = span._numbers;
	}
	return span;
}

// Member function

void Span::addNumber(const long nb) {
	if (_numbers.size() >= _N) {
		throw CantAddNumber();
	} else {
		_numbers.push_back(nb);
	}
}


size_t Span::shortestSpan(void) {

	if (_numbers.size() < 2) {
		throw ArrayTooSmall();
	}
	size_t shortestSpan;

	shortestSpan = std::numeric_limits<unsigned long>::max();
	for (size_t i = 1; i < _numbers.size(); ++i) {

		size_t	span = getSpan(_numbers[i], _numbers[i - 1]);
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
}

size_t Span::longestSpan(void) {

	if (_numbers.size() < 2) {
		throw ArrayTooSmall();
	}
	size_t longestSpan;

	longestSpan = 0;
	for (size_t i = 1; i < _numbers.size(); ++i) {

		size_t	span = getSpan(_numbers[i], _numbers[i - 1]);
		if (span > longestSpan)
			longestSpan = span;
	}
	return longestSpan;
}

// Destructor

Span::~Span() {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		RED << "deleted" << NC << std::endl;
	}
}

// Exceptions

const char *Span::CantAddNumber::what() const throw() {
	return "Cannot add number: Array is full";
}

const char *Span::ArrayTooSmall::what() const throw() {
	return "Cannot find a span: Array is too small";
}

// Private member functions

size_t Span::getSpan(const long nb1, const long nb2) {

	if ((nb1 > 0 && nb2 > 0)
		|| (nb1 < 0 && nb2 < 0)) {

		if (nb1 - nb2 > 0)
			return nb1 - nb2;
		return nb2 - nb1;
	} else {

		if (nb1 > 0)
			return nb1 - nb2;
		return nb2 - nb1;
	}
}