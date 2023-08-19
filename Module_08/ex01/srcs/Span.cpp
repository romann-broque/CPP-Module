/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:37:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:55:41 by rbroque          ###   ########.fr       */
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

Span &Span::operator=(Span &span) {

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
	std::vector<long> sortNumbers = _numbers;
	size_t shortestSpan;

	std::sort(sortNumbers.begin(), sortNumbers.end());
	shortestSpan = std::numeric_limits<long>::max();
	for (size_t i = 1; i < _numbers.size(); ++i) {

		size_t span = sortNumbers[i] - sortNumbers[i - 1];
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return shortestSpan;
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
	return "Cannot find the shortest span: Array is too small";
}

/////////////////// TO REMOVE //////////////////////

void Span::displaySpan(void) {

	for (size_t i = 0; i < _numbers.size(); ++i) {
		std::cout << _numbers[i] << std::endl;
	}
}

////////////////////////////////////////////////////