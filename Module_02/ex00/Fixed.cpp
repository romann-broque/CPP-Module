/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 15:19:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _nb(0)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Default constructor"
			<< NC << " called" << std::endl;
}

Fixed::Fixed(Fixed &fixed)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Copy constructor"
			<< NC << " called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	if (PRINT_DEBUG)
		std::cout << RED << "Destructor"
			<< NC << " called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed &fixed)
{
	if (PRINT_DEBUG)
		std::cout << BLUE << "Copy assignment operator"
			<< NC << " called" << std::endl;
	if (this != &fixed)
		this->_nb = fixed._nb;
	return (*this);
}

int	Fixed::getRawBits() const
{
	if (PRINT_DEBUG)
		std::cout << YELLOW << "getRawBits"
			<< NC << " member function called" << std::endl;
	return (_nb);
}

void	Fixed::setRawBits(int const raw)
{
	if (PRINT_DEBUG)
		std::cout << YELLOW << "setRawBits"
			<< NC << " member function called" << std::endl;
	this->_nb = raw;
}