/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:40:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(): _nb(0)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Default constructor"
			<< NC << " called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Copy constructor"
			<< NC << " called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int const nb)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Int constructor"
			<< NC << " called" << std::endl;
	_nb = nb << _fractPartSize;		
}

Fixed::Fixed(float const nb)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Float constructor"
			<< NC << " called" << std::endl;
	_nb = roundf(nb * (1 << _fractPartSize));
}

// Destructor

Fixed::~Fixed()
{
	if (PRINT_DEBUG)
		std::cout << RED << "Destructor"
			<< NC << " called" << std::endl;
}

// Overload operators

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	if (PRINT_DEBUG)
		std::cout << BLUE << "Copy assignment operator"
			<< NC << " called" << std::endl;
	if (this != &fixed)
		this->_nb = fixed._nb;
	return (*this);
}

std::ostream &operator<<(std::ostream &flux, Fixed const& fixed)
{
	flux << fixed.toFloat();
	return (flux);
}

// Member functions

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
	_nb = raw;
}

int	Fixed::toInt() const
{
	return (_nb >> _fractPartSize);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(_nb) / static_cast<float>(1 << _fractPartSize));
}