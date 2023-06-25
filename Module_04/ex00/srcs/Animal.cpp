/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:01:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 16:19:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors

Animal::Animal(): _type("UNKNOWN")
{
	if (PRINT_DEBUG)
		std::cout << "Animal has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	if (PRINT_DEBUG)
		std::cout << "Animal has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

Animal&	Animal::operator=(const Animal &animal)
{
	_type = animal._type;
	return (*this);
}

// Member functions

void	Animal::makeSound()
{
	std::cout << GREY << "*%!&$?#" << NC << std::endl;
}

// Destructor

Animal::~Animal()
{
	if (PRINT_DEBUG)
		std::cout << "Animal has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}