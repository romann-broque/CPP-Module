/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:48:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 09:24:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE),
	_target(DEFAULT_SHRUBBERY_TARGET) {

	if (PRINT_DEBUG)
	{
		std::cout << "ShrubberyCreationForm has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(SHRUBBERY_NAME, SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE), _target(target) {

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

void ShrubberyCreationForm::startExecution() const {
	
	// Create new file
	std::string fileName = _target + "_shrubbery";
	std::ofstream newFile(fileName.c_str(), std::ios_base::app);

	if (newFile.is_open()) {
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
				<< "   .....//||||\\...." << std::endl;
		// Close the file
		newFile.close();
	} else {
		// Handle the case when the file couldn't be opened.
		std::cerr << "Error opening the file: " << fileName << std::endl;
	}
}