/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:04:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 14:20:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors

Ice::Ice(): AMateria()
{
	_type = "ice";
	if (PRINT_DEBUG)
	{
		std::cout << "Ice has been"
			<< GREEN << " created (default)" << NC
			<< std::endl;
	}
}

Ice::Ice(const Ice &ice): AMateria(ice)
{
	*this = ice;
	if (PRINT_DEBUG)
	{
		std::cout << "Ice has been"
			<< GREEN << " created (copy)" << NC
			<< std::endl;
	}
}

Ice::Ice(std::string const &type): AMateria(type)
{
	_type = type;
	if (PRINT_DEBUG)
	{
		std::cout << "Ice has been"
			<< GREEN << " created (typeset)" << NC
			<< std::endl;
	}
}

// Overload assignment operator

Ice& Ice::operator=(Ice const &ice)
{
	this->_type = ice._type;
	return (*this);
}

// Getter

std::string const &Ice::getType() const
{
	return (_type);
}

// Member functions

Ice* Ice::clone() const
{
	Ice	*newIce = new Ice(*this);

	return (newIce);
}

// Destructor

Ice::~Ice()
{
	if (PRINT_DEBUG)
	{
		std::cout << "Ice has been"
			<< RED << " destroyed" << NC
			<< std::endl;
	}
}