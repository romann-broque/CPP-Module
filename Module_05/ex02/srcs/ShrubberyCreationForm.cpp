/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:48:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 23:21:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm(SHRUBBERY_NAME, 145, 137),
	_target(DEFAULT_TARGET) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(SHRUBBERY_NAME, 145, 137), _target(target) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm): AForm(shrubberyCreationForm) {

	*this = shrubberyCreationForm;
	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
	(void)shrubberyCreationForm;
	return *this;
}

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm() {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		RED << "deleted" << NC << std::endl;
	}
}

// Private

void ShrubberyCreationForm::startExecution() {
	std::cout << "Action by ShrubberyCreationForm on " << _target << std::endl;
}