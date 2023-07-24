/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:37:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 15:05:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors

Form::Form():
	_name(DEFAULT_NAME),
	_isSigned(false),
	_signGrade(DEFAULT_SIGN_GRADE),
	_execGrade(DEFAULT_EXEC_GRADE) {

	_isSigned = false;
	if (PRINT_DEBUG)
	{
		std::cout << "Form has been " <<
		GREEN << "created (default)" << NC
		<< std::endl;
	}
}

Form::Form(const std::string &name, const size_t signGrade, const size_t execGrade) {

	this->_name = name;
	this->_isSigned = false;
	assignGrade(this->_signGrade, signGrade);
	assignGrade(this->_execGrade, execGrade);
	if (PRINT_DEBUG)
	{
		std::cout << "Form has been " <<
		GREEN << "created (set)" << NC
		<< std::endl;
	}
}


Form::Form(const Form &form) {

	*this = form;
	if (PRINT_DEBUG)
	{
		std::cout << "Form has been " <<
		GREEN << "created (copy)" << NC
		<< std::endl;
	}
}

// Overload assignement operator

Form& Form::operator=(const Form &bureaucrat) {
	
	this->_name = bureaucrat._name;
	assignGrade(this->_signGrade, bureaucrat._signGrade);
	assignGrade(this->_execGrade, bureaucrat._execGrade);
	this->_isSigned = bureaucrat._isSigned;
	return *this;
}

// Getter

std::string const &Form::getName() const {
	return this->_name;
}

size_t Form::getSignGrade() const {
	return this->_signGrade;
}

size_t Form::getExecGrade() const {
	return this->_execGrade;
}

bool Form::isSigned() const {
	return this->_isSigned;
}

// Destructor

Form::~Form(){

	if (PRINT_DEBUG)
	{
		std::cout << "Form has been " <<
		RED << "deleted" << NC
		<< std::endl;
	}
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw (){
	return "Grade too high (must be inferior or equal to 1)";
}

const char *Form::GradeTooLowException::what() const throw (){
	return "Grade too low (must be superior or equal to 150)";
}

// Utils

void Form::assignGrade(size_t &dest, const size_t src) {
	
	if (src < 1)
		throw GradeTooHighException();
	else if (src > 150)
		throw GradeTooLowException();
	else
		dest = src;
}

// Overload outstream operator

std::ostream& operator<<(std::ostream& outStream, Form &form) {
	outStream << form.getName();
	if (form.isSigned())
		outStream << " has been signed";
	else
		outStream << " is not signed";
	outStream << " (SignGrade:" << form.getSignGrade()
	<< ", ExecGrade:" << form.getExecGrade() << ") ";
	return outStream;
}
