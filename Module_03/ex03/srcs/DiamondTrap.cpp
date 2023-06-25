/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:56:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 15:22:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors

DiamondTrap::DiamondTrap(): ClapTrap("Empty_clap_name")
{
	this->_name = "Empty";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	if (PRINT_DEBUG)
		std::cout << "DiamondTrap " << _name << " has been "
			<< GREEN << "created (default)" << NC << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	if (PRINT_DEBUG)
		std::cout << "DiamondTrap " << _name << " has been "
			<< GREEN << "created (nameset)" << NC << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap):
	ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	this->_name = diamondTrap._name;
	if (PRINT_DEBUG)
		std::cout << "DiamondTrap " << _name << " has been "
			<< GREEN << "created (copy)" << NC << std::endl;
}

//Overload assignment operator

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	*this = diamondTrap;
	return (*this);
}

// Member functions

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My complete name is "
	<< YELLOW << ClapTrap::_name << NC
	<< " and my little name is "
	YELLOW << _name << NC
	<< std::endl;
}

// Destructor

DiamondTrap::~DiamondTrap()
{
	if (PRINT_DEBUG)
		std::cout << "DiamondTrap " << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}