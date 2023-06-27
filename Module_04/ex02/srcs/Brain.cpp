/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:49:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 14:54:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors

Brain::Brain()
{
	if (PRINT_DEBUG)
		std::cout << "Brain has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
	if (PRINT_DEBUG)
		std::cout << "Brain has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

Brain&	Brain::operator=(const Brain &brain)
{
	for (size_t i(0); i < BRAIN_SIZE; ++i)
		_ideas[i] = brain._ideas[i];
	return (*this);
}

// Destructor

Brain::~Brain()
{
	if (PRINT_DEBUG)
		std::cout << "Brain has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}