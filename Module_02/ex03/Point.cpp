/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:59:15 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/23 14:55:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors

Point::Point(): x(0), y(0)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Point default constructor"
		NC << " called" << std::endl;
}

Point::Point(const float x_init, const float y_init): x(x_init), y(y_init)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Point set constructor"
		NC << " called" << std::endl;
}

Point::Point(Point &point): x(point.x), y(point.y)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Point copy constructor"
		NC << " called" << std::endl;
}

// Overload assignment operator

Point&	Point::operator=(__attribute__((unused))const Point &point)
{
	if (PRINT_DEBUG)
		std::cout << BLUE << "Copy assignment operator"
			<< NC << " called" << std::endl;
	return (*this);
}

// Member functions

float	Point::getDeltaX(const Point &p1, const Point &p2)
{
	return (p1.x - p2.x);
}

float	Point::getDeltaY(const Point &p1, const Point &p2)
{
	return (p1.y - p2.y);
}

// Destructor

Point::~Point()
{
	if (PRINT_DEBUG)
		std::cout << RED << "Point destructor"
		NC << " called" << std::endl;
}