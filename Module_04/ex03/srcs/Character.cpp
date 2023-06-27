/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:00:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 17:34:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors

Character::Character(): _name("Unknown")
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		_inventory[i] = NULL;
	if (PRINT_DEBUG)
	{
		std::cout << "Character has been "
		<< GREEN << "created (default)" << NC
		<< std::endl;
	}
}

Character::Character(const std::string &name): _name(name)
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		_inventory[i] = NULL;
	if (PRINT_DEBUG)
	{
		std::cout << "Character has been "
		<< GREEN << "created (nameset)" << NC
		<< std::endl;
	}
}

Character::Character(const Character &character)
{
	*this = character;
	if (PRINT_DEBUG)
	{
		std::cout << "Character has been "
		<< GREEN << "created (copy)" << NC
		<< std::endl;
	}
}

// Overload assignement operator

Character& Character::operator=(const Character &character)
{
	_name = character._name;
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		_inventory[i] = character._inventory[i]->clone();
	return (*this);
}

// Getter

std::string const	&Character::getName() const
{
	return (_name);
}

// Member functions

void	Character::equip(AMateria* m)
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < INVENTORY_SIZE)
		_inventory[idx] = NULL;
	// NEED: to manage dropped items
}


void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INVENTORY_SIZE)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
	}
}

// Destructor

Character::~Character()
{
	for (size_t i(0); i < INVENTORY_SIZE; ++i)
		delete _inventory[i];
	if (PRINT_DEBUG)
	{
		std::cout << "Character has been "
		<< RED << "destroyed" << NC
		<< std::endl;
	}
}