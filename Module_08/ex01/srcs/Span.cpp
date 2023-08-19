/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:37:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 09:42:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors

Span::Span(): _N(0) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< "numbers has been " <<
		GREEN << "created" << std::endl;
	}
}

Span::Span(const size_t N): _N(N) {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< "numbers has been " <<
		GREEN << "created" << std::endl;
	}
}

Span::Span(Span &span) {

	*this = span;
	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< "numbers has been " <<
		GREEN << "created (copy)" << std::endl;
	}
}

// Overload assignment operator

Span &Span::operator=(Span &span) {

	return span;
}

// Destructor

Span::~Span() {

	if (PRINT_DEBUG) {
		std::cout << "Span of " << _N
		<< "numbers has been " <<
		RED << "deleted" << std::endl;
	}
}