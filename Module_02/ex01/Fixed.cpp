/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 16:00:31 by rbroque          ###   ########.fr       */
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

Fixed::Fixed(int const nb): _nb(nb)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Int constructor"
			<< NC << " called" << std::endl;
}

Fixed::Fixed(float const nb): _nb(nb)
{
	if (PRINT_DEBUG)
		std::cout << GREEN << "Float constructor"
			<< NC << " called" << std::endl;
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

void Fixed::display(std::ostream &flux) const
{
	int	float_part = _nb & 16;
	int	nb = _nb >> _fractPartSize;

	flux << nb << "." << float_part;
}

std::ostream &operator<<(std::ostream &flux, Fixed const& fixed)
{
	fixed.display(flux);
	return (flux);
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