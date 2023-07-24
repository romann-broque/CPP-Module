/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 12:04:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat b1;
	Bureaucrat b2 = b1;
	Bureaucrat b3(b2);
	Bureaucrat b4("Detmold", 4);

	try
	{
		Bureaucrat b5("Detmold", 151);
	}
	catch(std::exception & e)
	{
		std::cout << "Bureaucrat is out of the system" << std::endl;
	}
}