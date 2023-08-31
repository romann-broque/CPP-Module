/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/31 14:58:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

////////////////////
// Static methods //
////////////////////

bool isOperator(const std::string &token) {
	return token.size() == 1 && token.find_first_of(OPERATORS) != std::string::npos;
}

int addition(const int nb1, const int nb2) {
	return (nb1 + nb2);
}

int substraction(const int nb1, const int nb2) {
	return (nb1 - nb2);
}

int multiplication(const int nb1, const int nb2) {
	return (nb1 * nb2);
}

int division(const int nb1, const int nb2) {
	return (nb1 / nb2); // protect against division by 0
}

int performOperation(const int nb1, const int nb2, const std::string &op) {

	static int (*operations[])(const int, const int) = {
		addition,
		substraction,
		multiplication,
		division
	};
	static std::string operators = OPERATORS;
	return operations[operators.find(op)](nb1, nb2);
}

int getOperand(const std::string &op) {
	if (op.size() == 1 && isdigit(op[0]))
		return op[0] - ASCII_NB_SHIFT;
	throw RPN::UnexpectedCharacterError();
}

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

////////////
// Member //
////////////

void	RPN::displayResult() {

	std::stack<int>		operands;
	std::istringstream	iss(_operationString);
	std::string			token;
	while (iss >> token) {

		if (isOperator(token)) {
			if (operands.size() < 2) {
				throw InsufficientOperandsError();
			}
			int operand1 = operands.top();
			operands.pop();
			int	operand2 = operands.top();
			operands.pop();
			int result = performOperation(operand1, operand2, token);
			operands.push(result);
		} else {
			const int operand = getOperand(token);
			operands.push(operand);
		}
	}
	if (operands.size() > 1)
		throw TooManyOperandsError();
	std::cout << operands.top() << std::endl;
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

const char *RPN::InsufficientOperandsError::what() const throw() {
	return INSUFFICIENT_OPERANDS_ERROR_M;
}

const char *RPN::TooManyOperandsError::what() const throw() {
	return TOO_MANY_OPERANDS_ERROR_M;
}

const char *RPN::UnexpectedCharacterError::what() const throw() {
	return UNEXPECTED_CHAR_ERROR_M;
}