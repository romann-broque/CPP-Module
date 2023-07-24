/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:13:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 23:14:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat(): _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {

	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< GREEN << "created (default)" << NC
		<< std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string &name, const size_t grade) {
	
	this->_name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< GREEN << "created (set)" << NC
		<< std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {

	*this = bureaucrat;
	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< GREEN << "created (copy)" << NC
		<< std::endl;
	}
}

// Overload assignement operator

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat) {

	this->_name = bureaucrat._name;
	this->_grade = bureaucrat._grade;
	return (*this);
}

// Member

void Bureaucrat::increaseGrade() {
	assignGrade(this->_grade, this->_grade - 1);
}

void Bureaucrat::decreaseGrade() {
	assignGrade(this->_grade, this->_grade + 1);
}

void Bureaucrat::signForm(AForm &form) {

	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed "
		<< form.getName() << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << this->_name << " couldn't sign "
		<< form.getName() << " because " << ex.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form) {

	try {
		form.execute(*this);
		std::cout << this->_name << " executed "
		<< form.getName() << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << this->_name << " couldn't execute "
		<< form.getName() << " because " << ex.what() << std::endl;
	}
}

// Getter

std::string const &Bureaucrat::getName() const {

	return this->_name;
}

size_t Bureaucrat::getGrade() const {

	return this->_grade;
}

// Destructor

Bureaucrat::~Bureaucrat() {

	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< RED << "deleted" << NC
		<< std::endl;
	}
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw (){
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw (){
	return "Grade is too low";
}

// Utils

void Bureaucrat::assignGrade(size_t &dest, const size_t src) {
	
	if (src < 1)
		throw GradeTooHighException();
	else if (src > 150)
		throw GradeTooLowException();
	else
		dest = src;
}

// Overload outstream operator

std::ostream& operator<<(std::ostream& outStream, Bureaucrat &bureaucrat){

	outStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outStream);
}