/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:33:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 10:00:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors

Intern::Intern() {

	if (PRINT_DEBUG)
	{
		std::cout << "Intern has been"
		GREEN << " created (default)" << NC << std::endl;
	}
}

Intern::Intern(Intern const &intern) {

	*this = intern;
	if (PRINT_DEBUG)
	{
		std::cout << "Intern has been"
		GREEN << " created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

Intern &Intern::operator=(Intern const &intern) {

	(void)intern;
	return (*this);
}

// Member

AForm *Intern::makeForm(const std::string const &name, const std::string const &target) {

	AForm *form;

	if (name == "robotomy request")
	{
		form = new RobotomyRequestForm(target);
	}
	else if (name == "presidential pardon")
	{
		form = new PresidentialPardonForm(target);
	}
	else if (name == "shrubbery creation")
	{
		form = new ShrubberyCreationForm(target);
	}
	else
	{
		std::cout << "Intern can't create form with name: "
		RED << name << NC << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);	
}

// Destructor

Intern::~Intern() {

	if (PRINT_DEBUG)
	{
		std::cout << "Intern has been"
		RED << " deleted" << NC << std::endl;
	}
}

// Private methods

AForm *Intern::makeRobotomyRequestForm(const std::string const &target) {

	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string const &target) {

	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeShrubberyCreationForm(const std::string const &target) {

	return (new ShrubberyCreationForm(target));
}
