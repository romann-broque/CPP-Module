/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 16:36:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main()
{
	Bureaucrat b1("Stanley", 127);
	Bureaucrat b2("CEO", 1);

	AForm f1("Protocol 42", 13, 56);

	AForm f2(f1);
	AForm f3 = f2;

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;
}