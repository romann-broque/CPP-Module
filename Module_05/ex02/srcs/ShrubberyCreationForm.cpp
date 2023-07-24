/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:48:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 21:34:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(DEFAULT_FORM_NAME, 145, 137) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): AForm(name, 145, 137) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm): AForm(shrubberyCreationForm) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignement operator

// ShrubberyCreationForm& operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
// 	this->_name = shrubberyCreationForm._name;
// 	this->_signGrade = shrubberyCreationForm._signGrade;
// 	this->_execGrade = shrubberyCreationForm._execGrade;
// 	this->_isSigned = shrubberyCreationForm._isSigned;
// 	return *this;
// }

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm() {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		RED << "deleted" << NC << std::endl;
	}
}

// Overload outstream operator

// std::ostream& operator<<(std::ostream& outStream, ShrubberyCreationForm &shrubberyCreationForm) {
// 	outStream << form.getName();
// 	if (form.isSigned())
// 		outStream << " has been signed";
// 	else
// 		outStream << " is not signed";
// 	outStream << " (SignGrade:" << form.getSignGrade()
// 	<< ", ExecGrade:" << form.getExecGrade() << ") ";
// 	return outStream;
// }

// Private

void ShrubberyCreationForm::startExecution() {
	std::cout << "Action by ShrubberyCreationForm" << std::endl;
}