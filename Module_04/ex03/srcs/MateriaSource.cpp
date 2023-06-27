/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:32:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 01:12:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors

MateriaSource::MateriaSource()
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		_slots[i] = NULL;
	if (PRINT_DEBUG)
	{
		std::cout << "MateriaSource has been "
		<< GREEN << "created (default)" << NC << std::endl;
	}
}

MateriaSource::MateriaSource(const MateriaSource &matSource)
{
	*this = matSource;
	if (PRINT_DEBUG)
	{
		std::cout << "MateriaSource has been "
		<< GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

MateriaSource&	MateriaSource::operator=(const MateriaSource &matSource)
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		_slots[i] = matSource._slots[i];
	return (*this);
}

// Member functions

void	MateriaSource::learnMateria(AMateria *amat)
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = amat; 
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
	{
		if (_slots[i] != NULL && _slots[i]->getType() == type)
			return (_slots[i]->clone());
	}
	return (0);
}

// Destructor

MateriaSource::~MateriaSource()
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		delete _slots[i];
	if (PRINT_DEBUG)
	{
		std::cout << "MateriaSource has been "
		<< RED << "destroyed" << NC << std::endl;
	}
}