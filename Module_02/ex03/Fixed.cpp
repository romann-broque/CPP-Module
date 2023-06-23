/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/23 14:50:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(): _nb(0){}

Fixed::Fixed(const Fixed &fixed): _nb(fixed._nb){}

Fixed::Fixed(int const nb): _nb(nb << _fractPartSize){}

Fixed::Fixed(float const nb): _nb(roundf(nb * (1 << _fractPartSize))){}

// Destructor

Fixed::~Fixed(){}

// Overload operators

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_nb = fixed._nb;
	return (*this);
}

// Overload arithmetic operators

float	Fixed::operator+(const Fixed &nb) const
{
	return (this->toFloat() + nb.toFloat());
}

float	Fixed::operator-(const Fixed &nb) const
{
	return (this->toFloat() - nb.toFloat());
}

float	Fixed::operator*(const Fixed &nb) const
{
	return (this->toFloat() * nb.toFloat());
}

float	Fixed::operator/(const Fixed &nb) const
{
	return (this->toFloat() / nb.toFloat());
}

// Overload pre-increment operators

Fixed&	Fixed::operator++()
{
	++_nb;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--_nb;
	return (*this);
}

// Overload post-increment operators

Fixed	Fixed::operator++(const int)
{
	Fixed tmp(*this);
	++_nb;
	return (tmp);
}

Fixed	Fixed::operator--(const int)
{
	Fixed tmp(*this);
	--_nb;
	return (tmp);
}

// Overload comparaison operators

bool	Fixed::operator==(const Fixed &nb) const
{
	return (this->toFloat() == nb.toFloat());
}

bool	Fixed::operator!=(const Fixed &nb) const
{
	return (this->toFloat() != nb.toFloat());
}

bool	Fixed::operator<(const Fixed &nb) const
{
	return (this->toFloat() < nb.toFloat());
}

bool	Fixed::operator<=(const Fixed &nb) const
{
	return (*this < nb || *this == nb);
}

bool	Fixed::operator>(const Fixed &nb) const
{
	return (this->toFloat() > nb.toFloat());
}

bool	Fixed::operator>=(const Fixed &nb) const
{
	return (*this > nb || *this == nb);
}

// Overload flux operator

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

Fixed&	Fixed::min(Fixed &nb1, Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::min(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

Fixed&	Fixed::max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::max(const Fixed &nb1, const Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}