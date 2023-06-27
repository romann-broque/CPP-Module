/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:29:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 14:30:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors

Cure::Cure(): AMateria()
{
	_type = "cure";
	if (PRINT_DEBUG)
	{
		std::cout << "Cure has been"
			<< GREEN << " created (default)" << NC
			<< std::endl;
	}
}

Cure::Cure(const Cure &cure): AMateria(cure)
{
	*this = cure;
	if (PRINT_DEBUG)
	{
		std::cout << "Cure has been"
			<< GREEN << " created (copy)" << NC
			<< std::endl;
	}
}

Cure::Cure(std::string const &type): AMateria(type)
{
	_type = type;
	if (PRINT_DEBUG)
	{
		std::cout << "Cure has been"
			<< GREEN << " created (typeset)" << NC
			<< std::endl;
	}
}

// Overload assignment operator

Cure& Cure::operator=(Cure const &cure)
{
	this->_type = cure._type;
	return (*this);
}

// Getter

std::string const &Cure::getType() const
{
	return (_type);
}

// Member functions

Cure* Cure::clone() const
{
	Cure	*newCure = new Cure(*this);

	return (newCure);
}

// Destructor

Cure::~Cure()
{
	if (PRINT_DEBUG)
	{
		std::cout << "Cure has been"
			<< RED << " destroyed" << NC
			<< std::endl;
	}
}