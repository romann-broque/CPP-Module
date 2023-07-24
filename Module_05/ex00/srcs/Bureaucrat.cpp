/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:13:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 10:18:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat() {

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
	// if (grade < 1)
	// 	throw
	// else if (grade > 150)
	// 	throw
	this->name = name;
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


Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->name = bureaucrat.name;
	this->grade = bureaucrat.grade;
	return (*this);
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