/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:21:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 09:06:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors

RobotomyRequestForm::RobotomyRequestForm():
	AForm(ROBOTOMY_NAME, ROBOT_SIGN_GRADE, ROBOT_EXEC_GRADE),
	_target(DEFAULT_ROBOT_TARGET) {

	if (PRINT_DEBUG)
	{
		std::cout << "RobotomyRequestForm has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm(ROBOTOMY_NAME, ROBOT_SIGN_GRADE, ROBOT_EXEC_GRADE), _target(target) {

	if (PRINT_DEBUG)
	{
		std::cout << "RobotomyRequestForm has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm): AForm(robotomyRequestForm) {

	*this = robotomyRequestForm;
	if (PRINT_DEBUG)
	{
		std::cout << "RobotomyRequestForm has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm) {
	(void)robotomyRequestForm;
	return *this;
}

// Destructor

RobotomyRequestForm::~RobotomyRequestForm() {

	if (PRINT_DEBUG)
	{
		std::cout << "RobotomyRequestForm has been " <<
		RED << "deleted" << NC << std::endl;
	}
}

// Private

void RobotomyRequestForm::startExecution() {
	
	std::cout << "Drrrrrrr...... Bzzzzzzz..... Krrrrrr!" << std::endl;
	std::srand(static_cast<unsigned>(std::time(0)));
	if (rand() % 2 == 1) {
		std::cout << _target << " has been robotized" << std::endl;
	}
	else {
		std::cout << "Robotization failed" << std::endl;
	}
}