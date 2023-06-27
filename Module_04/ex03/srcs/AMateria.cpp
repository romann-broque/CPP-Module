/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:10:45 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 16:59:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors

AMateria::AMateria(): _type("Unknown")
{
	if (PRINT_DEBUG)
	{
		std::cout << "AMateria has been"
			<< GREEN << " created (default)" << NC
			<< std::endl;
	}
}

AMateria::AMateria(const AMateria &amateria)
{
	*this = amateria;
	if (PRINT_DEBUG)
	{
		std::cout << "AMateria has been"
			<< GREEN << " created (copy)" << NC
			<< std::endl;
	}
}

AMateria::AMateria(std::string const &type): _type(type)
{
	if (PRINT_DEBUG)
	{
		std::cout << "AMateria has been"
			<< GREEN << " created (typeset)" << NC
			<< std::endl;
	}
}

// Overload assignment operator

AMateria& AMateria::operator=(AMateria const &amateria)
{
	this->_type = amateria._type;
	return (*this);
}

// Getter

std::string const &AMateria::getType() const
{
	return (_type);
}

// Member functions

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

// Destructor

AMateria::~AMateria()
{
	if (PRINT_DEBUG)
	{
		std::cout << "AMateria has been"
			<< RED << " destroyed" << NC
			<< std::endl;
	}
}