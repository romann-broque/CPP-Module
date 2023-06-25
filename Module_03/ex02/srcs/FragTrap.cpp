/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:33:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 13:32:10 by rbroque          ###   ########.fr       */
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

void	FragTrap::highFivesGuys()
{
	std::cout << YELLOW << _name << NC
	<< " is asking for a "
	<< CYAN << "high fives" << NC
	<< std::endl;
}

// Destructor

FragTrap::~FragTrap()
{
	if (PRINT_DEBUG)
		std::cout << "FragTrap " << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}