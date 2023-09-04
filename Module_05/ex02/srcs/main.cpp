/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 13:39:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat b1("Stanley", 138);
	Bureaucrat b2("CEO", 1);

	// SHRUBBERY

	// ShrubberyCreationForm f1("target3");
	// ShrubberyCreationForm f2(f1);

	// std::cout << f1 << std::endl;
	// std::cout << f2 << std::endl;
	// f1 = f2;
	// std::cout << f1 << std::endl;

	// b1.signForm(f1);
	// b1.executeForm(f1);
	// std::cout << b1 << std::endl;	
	// b1.increaseGrade();
	// std::cout << b1 << std::endl;	
	// b1.executeForm(f1);

	// ROBOTOMY

	// Bureaucrat jack("Jack", 36);
	// RobotomyRequestForm bot1("Clap trap");

	// b1.signForm(bot1);
	// std::cout << b1 << std::endl;
	// b2.signForm(bot1);
	// jack.executeForm(bot1);

	// PRESIDENT

	// PresidentialPardonForm pardon1("Marvin");

	// b1.signForm(pardon1);
	// b2.signForm(pardon1);
	// b2.signForm(pardon1);
	// b2.executeForm(pardon1);

	// Some random tests

	// PresidentialPardonForm pardon1("Marvin");

	// b1.signForm(pardon1);
	// b2.executeForm(pardon1);
	// b2.signForm(pardon1);
	// b2.signForm(pardon1);
	// b2.executeForm(pardon1);
}