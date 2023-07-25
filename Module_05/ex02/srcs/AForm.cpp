/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:32:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 09:22:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors

AForm::AForm():
	_name(DEFAULT_FORM_NAME),
	_isSigned(false),
	_signGrade(DEFAULT_SIGN_GRADE),
	_execGrade(DEFAULT_EXEC_GRADE) {

	_isSigned = false;
	if (PRINT_DEBUG)
	{
		std::cout << "AForm has been " <<
		GREEN << "created (default)" << NC
		<< std::endl;
	}
}

AForm::AForm(
	const std::string &name,
	const size_t signGrade,
	const size_t execGrade) {

	this->_name = name;
	this->_isSigned = false;
	assignGrade(this->_signGrade, signGrade);
	assignGrade(this->_execGrade, execGrade);
	if (PRINT_DEBUG)
	{
		std::cout << "AForm has been " <<
		GREEN << "created (set)" << NC
		<< std::endl;
	}
}


AForm::AForm(const AForm &form) {

	*this = form;
	if (PRINT_DEBUG)
	{
		std::cout << "AForm has been " <<
		GREEN << "created (copy)" << NC
		<< std::endl;
	}
}

// Overload assignement operator

AForm& AForm::operator=(const AForm &bureaucrat) {
	
	assignGrade(this->_signGrade, bureaucrat._signGrade);
	assignGrade(this->_execGrade, bureaucrat._execGrade);
	this->_name = bureaucrat._name;
	this->_isSigned = bureaucrat._isSigned;
	return *this;
}

// Member

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned && executor.getGrade() <= _execGrade)
		startExecution();
	else
		throw GradeTooLowException();
}

// Getter

std::string const &AForm::getName() const {
	return this->_name;
}

size_t AForm::getSignGrade() const {
	return this->_signGrade;
}

size_t AForm::getExecGrade() const {
	return this->_execGrade;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

// Destructor

AForm::~AForm(){

	if (PRINT_DEBUG)
	{
		std::cout << "AForm has been " <<
		RED << "deleted" << NC
		<< std::endl;
	}
}

// Exceptions

const char *AForm::GradeTooHighException::what() const throw (){
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw (){
	return "Grade is too low";
}

// Utils

void AForm::assignGrade(size_t &dest, const size_t src) {
	
	if (src < 1)
		throw GradeTooHighException();
	else if (src > 150)
		throw GradeTooLowException();
	else
		dest = src;
}

// Overload outstream operator

std::ostream& operator<<(std::ostream& outStream, AForm &form) {
	outStream << form.getName();
	if (form.isSigned())
		outStream << " has been signed";
	else
		outStream << " is not signed";
	outStream << " (SignGrade:" << form.getSignGrade()
	<< ", ExecGrade:" << form.getExecGrade() << ") ";
	return outStream;
}
