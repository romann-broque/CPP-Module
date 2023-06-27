/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:23:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 16:29:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors

Cat::Cat()
{
	_type = "Cat";
	if (PRINT_DEBUG)
		std::cout << "Cat has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	*this = cat;
	if (PRINT_DEBUG)
		std::cout << "Cat has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

Cat&	Cat::operator=(const Cat &cat)
{
	_type = cat._type;
	return (*this);
}

// Member functions

void	Cat::makeSound() const
{
	std::cout << GREY << "Miaaaaouh" << NC << std::endl;
}

// Destructor

Cat::~Cat()
{
	if (PRINT_DEBUG)
		std::cout << "Cat has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}