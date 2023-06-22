/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/22 14:48:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.21f);
	Fixed const d(-42.21f);

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "b + c = " << b + c << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "d - b = " << d - b << std::endl;
	return (EXIT_SUCCESS);
}