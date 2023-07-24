/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:13:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 15:34:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat(): name(DEFAULT_NAME), grade(DEFAULT_GRADE) {

	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< GREEN << "created (default)" << NC
		<< std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string &name, const size_t grade) {
	
	if (PRINT_DEBUG)
	{
		std::cout << "Bureaucrat has been "
		<< GREEN << "created (set)" << NC
		<< std::endl;
	}
	this->name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
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

	this->name = bureaucrat.name;
	this->grade = bureaucrat.grade;
	return (*this);
}

// Member

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}	
	catch (std::exception & e) {
		std::cout << this->name << " couldn't sign " << form.getName()
		<< " because " << std::endl;
	}
}

// Getter

std::string const &Bureaucrat::getName() const {

	return this->name;
}

size_t Bureaucrat::getGrade() const {

	return this->grade;
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
	return "Grade too high (must be inferior or equal to 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw (){
	return "Grade too low (must be superior or equal to 150)";
}

// Overload outstream operator

std::ostream& operator<<(std::ostream& outStream, Bureaucrat &bureaucrat){

	outStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outStream);
}