/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:35:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 16:51:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors

Dog::Dog()
{
	_type = "Dog";
	if (PRINT_DEBUG)
		std::cout << "Dog has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	*this = dog;
	if (PRINT_DEBUG)
		std::cout << "Dog has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

Dog&	Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	return (*this);
}

// Member functions

void	Dog::makeSound() const
{
	std::cout << GREY << "Wouaf Wouaf!" << NC << std::endl;
}

// Destructor

Dog::~Dog()
{
	if (PRINT_DEBUG)
		std::cout << "Dog has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}