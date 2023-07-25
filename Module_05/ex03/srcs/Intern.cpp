/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:33:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 13:22:19 by rbroque          ###   ########.fr       */
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

struct FormKind {
	std::string name;
	AForm *(Intern::*makeForm)(const std::string &target);
};

// Member

AForm *Intern::makeForm(const std::string &name, const std::string &target) {

	FormKind formKind[FORM_KIND_COUNT] = {
		{ "robotomy request", &Intern::makeRobotomyRequestForm },
		{ "presidential pardon", &Intern::makePresidentialPardonForm },
		{ "shrubbery creation", &Intern::makeShrubberyCreationForm }
	};

	for (int i = 0; i < FORM_KIND_COUNT; i++) {
		if (name == formKind[i].name) {
			std::cout << "Intern creates " << formKind[i].name << std::endl;
			return (this->*(formKind[i].makeForm))(target);
		}
	}

	std::cout << "Intern can't create form with name: "
		<< RED << name << NC << std::endl;
	return NULL;
}

// Destructor

Intern::~Intern() {

	if (PRINT_DEBUG)
	{
		std::cout << "Intern has been"
		RED << " deleted" << NC << std::endl;
	}
}

// Private

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {

	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {

	return new PresidentialPardonForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {

	return new ShrubberyCreationForm(target);
}