/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:12:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 09:16:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors

PresidentialPardonForm::PresidentialPardonForm():
	AForm(PRESIDENTIAL_NAME, PRESIDENT_SIGN_GRADE, PRESIDENT_EXEC_GRADE),
	_target(DEFAULT_PRESIDENT_TARGET) {

	if (PRINT_DEBUG)
	{
		std::cout << "PresidentialPardonForm has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm(PRESIDENTIAL_NAME, PRESIDENT_SIGN_GRADE, PRESIDENT_EXEC_GRADE), _target(target) {

	if (PRINT_DEBUG)
	{
		std::cout << "PresidentialPardonForm has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm): AForm(presidentialPardonForm) {

	*this = presidentialPardonForm;
	if (PRINT_DEBUG)
	{
		std::cout << "PresidentialPardonForm has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm) {
	(void)presidentialPardonForm;
	return *this;
}

// Destructor

PresidentialPardonForm::~PresidentialPardonForm() {

	if (PRINT_DEBUG)
	{
		std::cout << "PresidentialPardonForm has been " <<
		RED << "deleted" << NC << std::endl;
	}
}

// Private

void PresidentialPardonForm::startExecution() {
	
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}