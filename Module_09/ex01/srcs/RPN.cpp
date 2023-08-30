/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/30 09:30:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//////////////////
// Constructors //
//////////////////

RPN::RPN() {
	if (PRINT_DEBUG) {
		std::cout << "RPN has been " <<
		GREEN << "created (empty)" << NC << std::endl;
	}
}

RPN::RPN(const RPN &other) {
	*this = other;
	if (PRINT_DEBUG) {
		std::cout << "RPN has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

RPN::RPN(const int argCount, const char *operationString) {
	if (argCount < EXPECTED_ARG_COUNT)
		throw MissingArgumentError();
	if (argCount > EXPECTED_ARG_COUNT)
		throw TooManyArgumentError();
	_operationString = operationString;
}

//////////////////////////////////
// Overload assignment operator //
//////////////////////////////////

RPN &RPN::operator=(const RPN &other) {
	this->_operationString = other._operationString;
	return *this;
}

////////////////
// Destructor //
////////////////

RPN::~RPN() {
	if (PRINT_DEBUG) {
		std::cout << "RPN has been " <<
		RED << "destroyed" << NC << std::endl;
	}
}

////////////////
// Exceptions //
////////////////

const char *RPN::MissingArgumentError::what() const throw() {
	return MISSING_ARG_ERROR_M;
}

const char *RPN::TooManyArgumentError::what() const throw() {
	return TOO_MANY_ARG_ERROR_M;
}