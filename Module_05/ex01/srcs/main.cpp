/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 15:05:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	// Bureaucrat b1;
	// Bureaucrat b2 = b1;
	// Bureaucrat b3(b2);
	// Bureaucrat b4("Detmold", 5);
	// Bureaucrat b5("Coffee", 112);
	// Bureaucrat b6("Machine", 149);
	// Bureaucrat b7("CEO", 1);

	// try
	// {
	// 	Bureaucrat invalid("Detmold", 151);
	// 	std::cout << invalid << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << "Bureaucrat is smashed by the system" << std::endl;
	// }
	// try
	// {
	// 	Bureaucrat invalid("Detmold", 151);
	// 	std::cout << invalid << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << "Bureaucrat is out of the system" << std::endl;
	// }

	// std::cout << b1 << std::endl;
	// std::cout << b2 << std::endl;
	// std::cout << b3 << std::endl;
	// std::cout << b4 << std::endl;
	// std::cout << b5 << std::endl;
	// std::cout << b6 << std::endl;
	// std::cout << b7 << std::endl;

	Form f1("Protocol 42", 13, 56);

	Form f2(f1);
	Form f3 = f2;

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
}