/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:13:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 11:20:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	if (PRINT_DEBUG)
		std::cout << "ScavTrap " << _name << " has been "
			<< GREEN << "created (default)" << NC << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	if (PRINT_DEBUG)
		std::cout << "ScavTrap " << _name << " has been "
			<< GREEN << "created (nameset)" << NC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap)
{
	if (PRINT_DEBUG)
		std::cout << "ScavTrap " << _name << " has been "
			<< GREEN << "created (copy)" << NC << std::endl;
}

//Overload assignment operator

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap)
{
	*this = scavtrap;
	return (*this);
}

// Member functions

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap ";
	attackAction(target);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap ";
	takeDamageAction(amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap ";
	beRepairedAction(amount);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap "
		<< YELLOW << _name << NC
		<< " is now in"
		<< CYAN << " Gate Keeper" << NC
		<< " mode" << std::endl;
}

// Destructor

ScavTrap::~ScavTrap()
{
	if (PRINT_DEBUG)
		std::cout << "ScavTrap " << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}