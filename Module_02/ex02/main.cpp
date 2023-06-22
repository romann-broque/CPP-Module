/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/22 15:17:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.21f);
	Fixed const d(-42.21f);
	Fixed const e(0);
	Fixed const f(0);

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << c << " / " << e << " = " << c / e << std::endl;
	std::cout << d << " / " << e << " = " << d / e << std::endl;
	std::cout << d << "==" << e << " ? " << (d == e) << std::endl;
	std::cout << f << "==" << e << " ? " << (f == e) << std::endl;
	std::cout << f << "<" << e << " ? " << (f < e) << std::endl;
	std::cout << a << "<=" << b << " ? " << (a <= b) << std::endl;
	std::cout << a << ">" << b << " ? " << (a > b) << std::endl;
	std::cout << a << ">=" << b << " ? " << (a >= b) << std::endl;
	std::cout << a << "!=" << b << " ? " << (a != b) << std::endl;
	std::cout << e << "!=" << f << " ? " << (e != f) << std::endl;

	return (EXIT_SUCCESS);
}