/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/23 15:22:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(
	Point const a,
	Point const b,
	Point const c,
	Point const point
	);

int	main()
{
	Point	a(1, 3);
	Point	b(3, 4);
	Point	c(3, 1);
	Point	p(2.67, 3.18);

	std::cout << bsp(a, b, c, p) << std::endl;
	return (EXIT_SUCCESS);
}