/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:48:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 08:15:04 by rbroque          ###   ########.fr       */
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
	
	std::string fileName = _target + "_shrubbery";
	std::ofstream newFile(fileName.c_str());

	// Write to the file
	newFile << "   ccee88oo" << std::endl
			<< " C8O8O8Q8PoOb o8oo" << std::endl
			<< " dOB69QO8PdUOpugoO9bD" << std::endl
			<< "CgggbU8OU qOp qOdoUOdcb" << std::endl
			<< "    6OuU  /p u gcoUodpP" << std::endl
			<< "      \\\\//  /douUP" << std::endl
			<< "        \\\\////" << std::endl
			<< "         |||/\\" << std::endl
			<< "         |||\\/" << std::endl
			<< "         |||||" << std::endl
			<< "   .....//||||\\...." << std::endl

	// Close the file
	newFile.close();
}