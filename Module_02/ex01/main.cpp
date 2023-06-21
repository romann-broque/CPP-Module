/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 16:01:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	// Default Constructor

	Fixed	fix1;

	fix1.setRawBits(35);

	// Copy Constructor

	Fixed	fix2(fix1);

	// Assignement Constructor

	Fixed	fix3;

	fix3 = fix2;

	Fixed	fix4(21);
	Fixed	fix5((float)(42.21));

	// getRawbits

	fix1.setRawBits(42);
	std::cout << fix1.getRawBits() << std::endl; 	
	std::cout << fix2.getRawBits() << std::endl; 	
	std::cout << fix3.getRawBits() << std::endl; 	
	std::cout << fix4.getRawBits() << std::endl; 	
	std::cout << fix5.getRawBits() << std::endl; 	
	std::cout << std::endl;
	std::cout << fix1 << std::endl;
	std::cout << fix2 << std::endl;
	std::cout << fix3 << std::endl;
	std::cout << fix4 << std::endl;

	return (EXIT_SUCCESS);
}