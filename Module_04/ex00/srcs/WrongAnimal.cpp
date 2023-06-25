/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:27:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 17:27:56 by rbroque          ###   ########.fr       */
/*  o                                                                          */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors

WrongAnimal::WrongAnimal(): _type("Unknown")
{
	if (PRINT_DEBUG)
		std::cout << "WrongAnimal has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	if (PRINT_DEBUG)
		std::cout << "WrongAnimal has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	_type = wrongAnimal._type;
	return (*this);
}

// Member functions

void	WrongAnimal::makeSound() const
{
	std::cout << GREY << "*%!&$?#" << NC << std::endl;
}

// Getter

std::string	WrongAnimal::getType() const
{
	return (_type);
}

// Destructor

WrongAnimal::~WrongAnimal()
{
	if (PRINT_DEBUG)
		std::cout << "WrongAnimal has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}