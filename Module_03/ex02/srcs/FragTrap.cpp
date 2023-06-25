/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:33:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 11:47:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	if (PRINT_DEBUG)
		std::cout << "FragTrap " << _name << " has been "
			<< GREEN << "created (default)" << NC << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	if (PRINT_DEBUG)
		std::cout << "FragTrap " << _name << " has been "
			<< GREEN << "created (nameset)" << NC << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap): ClapTrap(FragTrap)
{
	if (PRINT_DEBUG)
		std::cout << "FragTrap " << _name << " has been "
			<< GREEN << "created (copy)" << NC << std::endl;
}

//Overload assignment operator

FragTrap& FragTrap::operator=(const FragTrap &FragTrap)
{
	*this = FragTrap;
	return (*this);
}

// Member functions

void	FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap ";
	attackAction(target);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap ";
	takeDamageAction(amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap ";
	beRepairedAction(amount);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap "
	<< YELLOW << _name << NC
	<< " is asking for a "
	<< CYAN << "high fives" << NC
	<< "!" << std::endl;
}

// Destructor

FragTrap::~FragTrap()
{
	if (PRINT_DEBUG)
		std::cout << "FragTrap " << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}