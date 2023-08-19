/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:37:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:11:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors

Span::Span(): _N(0), _setValue(0), _numbers(new long(_N)) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		GREEN << "created" << NC << std::endl;
	}
	bzero(_numbers, _N * sizeof(long));
}

Span::Span(const size_t N): _N(N), _setValue(0), _numbers(new long(_N)) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< " numbers has been " <<
		GREEN << "created" << NC << std::endl;
	}
	memset(_numbers, 1, _N * sizeof(long));
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
		delete []_numbers;
		_N = span._N;
		_setValue = span._setValue;
		_numbers = new long(_N);
		for (size_t i = 0; i < _N; ++i) {
			// add Number
			_numbers[i] = span._numbers[i];
		}
	}
	return span;
}

// Member function

void Span::addNumber(const long nb) {
	if (_setValue >= _N) {
		throw CantAddNumber();
	} else {
		_numbers[_setValue] = nb;
		++_setValue;
	}
}

// Destructor

Span::~Span() {

	delete _numbers;
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

/////////////////// TO REMOVE //////////////////////

void Span::displaySpan(void) {
	for (size_t i = 0; i < _setValue; ++i) {
		std::cout << _numbers[i] << std::endl;
	}
}

////////////////////////////////////////////////////