/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:26:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:56:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	if (PRINT_DEBUG)
		std::cout << _name << " has been "
			<< GREEN << "created" << NC << std::endl;
}

HumanB::~HumanB()
{
	if (PRINT_DEBUG)
		std::cout << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}

void	HumanB::attack() const
{
	if (_weapon == NULL)
		std::cout << _name << " has no weapon and "
			<< YELLOW << "can't attack" << NC << std::endl;
	else
		std::cout << _name << YELLOW << " attacks " << NC << "with their "
			<< YELLOW << _weapon->getType() << NC << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}