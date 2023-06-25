/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 10:19:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors

ClapTrap::ClapTrap():
	_name("Empty"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (PRINT_DEBUG)
		std::cout << "ClapTrap " << _name << " has been "
			<< GREEN << "created (default)" << NC << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (PRINT_DEBUG)
		std::cout << "ClapTrap " << _name << " has been "
			<< GREEN << "created (nameset)" << NC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	if (PRINT_DEBUG)
		std::cout << "ClapTrap " << _name << " has been "
			<< GREEN << "created (copy)" << NC << std::endl;
}

// Overload assignment operator

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap)
{
	this->_name = claptrap._name;
	this->_hitPoints = claptrap._hitPoints;
	this->_energyPoints = claptrap._energyPoints;
	this->_attackDamage = claptrap._attackDamage;
	return (*this);
}

// Member functions

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << YELLOW << _name << NC << " is "
		<< RED << "dead" << NC << " and can't attack" << std::endl;
	else if (_energyPoints == 0)
		std::cout << YELLOW << _name << NC
			<< RED << " can't attack because has no more energy" << NC << std::endl;
	else
	{
		std::cout << "ClapTrap " << YELLOW << _name << NC
			<< MAGENTA << " attacks " << NC << YELLOW << target << NC << ", causing "
			<< RED << _attackDamage << NC << " points of damage!" << std::endl;
		--_energyPoints;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << YELLOW << _name << NC
			<< " has been attacked and loses "
			<< RED << amount << NC
			<< " hit points!";
		if (_hitPoints <= amount)
		 std::cout << " " << YELLOW << _name << NC << RED << " died" << NC;
		std::cout << std::endl;
	}
	else
		std::cout << "Wouah! Calm down! "
			<< YELLOW << _name << NC 
			<< RED << " is already dead" << NC << std::endl;
	if (_hitPoints <= amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << YELLOW << _name << NC << " is "
			<< RED << "dead" << NC << " and can't be repaired" << std::endl;
	else if (_energyPoints == 0)
		std::cout << YELLOW << _name << NC << " has "
			<< RED << "no more energy " << NC << "to repair" << std::endl;
	else
	{
		std::cout << "ClapTrap " << YELLOW << _name << NC
			<< BLUE " repairs " << NC << "and gains "
			<< GREEN << amount << NC
			<< " hit points!" << std::endl;
		--_energyPoints;
	}
}

// Destructor

ClapTrap::~ClapTrap()
{
	if (PRINT_DEBUG)
		std::cout << "ClapTrap " << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}