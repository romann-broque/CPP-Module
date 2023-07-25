/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 13:49:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	b1("Stanley", 138);
	Bureaucrat	b2("CEO", 1);

	/// SHRUBBERY ///

	// Intern		slave;
	// AForm		*formPtr;
	
	// formPtr = slave.makeForm("shrubbery creation", "garden");
	// b2.executeForm(*formPtr);
	// b1.signForm(*formPtr);
	// b2.executeForm(*formPtr);
	// b2.executeForm(*formPtr);
	// delete formPtr;
	
	/// ROBOTOMY ///
	
	// Intern		slave;
	// AForm		*formPtr;
	
	// formPtr = slave.makeForm("robotomy request", "Clank");
	// b2.executeForm(*formPtr);
	// b1.signForm(*formPtr);
	// b2.signForm(*formPtr);
	// b2.executeForm(*formPtr);
	// b2.executeForm(*formPtr);
	// std::cout << *formPtr << std::endl;
	// std::cout << b2 << std::endl;
	// delete formPtr;
	
	/// UNKNOWN FORM ///

	// Intern		slave;
	// AForm		*formPtr;
	
	// formPtr = slave.makeForm("weird stuff form", "what?");
	// delete formPtr;
}