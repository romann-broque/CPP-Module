/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:53:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/22 16:06:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

////////////////////
// Static methods //
////////////////////

static bool isOperator(const std::string &token) {
	return token.size() == 1 && token.find_first_of(OPERATORS) != std::string::npos;
}

static int addition(const int nb1, const int nb2) {

	if (nb1 > INT_MAX - nb2)
		throw RPN::OverflowError();
	return (nb1 + nb2);
}

static int substraction(const int nb1, const int nb2) {
	if (nb1 < INT_MIN + nb2)
		throw RPN::OverflowError();
	return (nb1 - nb2);
}

static int multiplication(const int nb1, const int nb2) {

	if (nb1 != 0 && nb2 != 0) {
		if (nb1 > INT_MAX / nb2)
			throw RPN::OverflowError();
	}
	return (nb1 * nb2);
}

static int division(const int nb1, const int nb2) {
	if (nb2 == 0)
		throw RPN::DivisionByZeroError();
	return (nb1 / nb2); // protect against division by 0
}

static int performOperation(const int nb1, const int nb2, const std::string &op) {

	static int (*operations[])(const int, const int) = {
		addition,
		substraction,
		multiplication,
		division
	};
	static std::string operators = OPERATORS;
	return operations[operators.find(op)](nb1, nb2);
}

static int getOperand(const std::string &op) {
	if (op.size() == 1 && isdigit(op[0]))
		return op[0] - ASCII_NB_SHIFT;
	throw RPN::UnexpectedTokenError();
}

static bool	isEmpty(const std::string &str) {

	for (size_t	i = 0; i < str.length(); ++i) {
		if (std::isspace(str[i]) == false)
			return (false);
	}
	return (true);
}

//////////////////
// Constructors //
//////////////////

// Cannot be used
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

RPN::RPN(const int argCount, const std::string operationString) {
	if (argCount < EXPECTED_ARG_COUNT)
		throw MissingArgumentError();
	if (argCount > EXPECTED_ARG_COUNT)
		throw TooManyArgumentError();
	if (isEmpty(operationString))
		throw EmptyStringError();
	_operationString = operationString;
	if (PRINT_DEBUG) {
		std::cout << "RPN has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
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

void	RPN::displayResult() const {

	std::stack<int> operands;
	processStack(operands);
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

const char *RPN::EmptyStringError::what() const throw() {
	return EMPTY_STRING_ERROR_M;
}

const char *RPN::InsufficientOperandsError::what() const throw() {
	return INSUFFICIENT_OPERANDS_ERROR_M;
}

const char *RPN::TooManyOperandsError::what() const throw() {
	return TOO_MANY_OPERANDS_ERROR_M;
}

const char *RPN::UnexpectedTokenError::what() const throw() {
	return UNEXPECTED_TOK_ERROR_M;
}

const char *RPN::DivisionByZeroError::what() const throw() {
	return DIVISION_BY_ZERO_ERROR_M;
}

const char *RPN::OverflowError::what() const throw() {
	return OVERFLOW_ERROR_M;
}

/////////////
// Private //
/////////////

void RPN::processStack(std::stack<int> &operands) const {
	std::istringstream	iss(_operationString);
	std::string			token;
	while (iss >> token) {

		if (isOperator(token)) {
			if (operands.size() < 2) {
				throw InsufficientOperandsError();
			}
			const int operand1 = operands.top();
			operands.pop();
			const int	operand2 = operands.top();
			operands.pop();
			const int result = performOperation(operand2, operand1, token);
			operands.push(result);
		} else {
			const int operand = getOperand(token);
			operands.push(operand);
		}
	}
}
