/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 21:35:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat b1("Stanley", 127);
	Bureaucrat b2("CEO", 1);
	ShrubberyCreationForm f1("Protocol 42");

	std::cout << f1 << std::endl;

	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;
}