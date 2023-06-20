/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:25:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:52:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(&weapon)
{
	if (PRINT_DEBUG)
		std::cout << _name << " has been "
			<< GREEN << "created" << NC << std::endl;
}

HumanA::~HumanA()
{
	if (PRINT_DEBUG)
		std::cout << _name << " has been "
			<< RED << "destroyed" << NC << std::endl;
}

void	HumanA::attack() const
{
	std::cout << _name << YELLOW << " attacks " << NC << "with their "
		<< YELLOW << _weapon->getType() << NC << std::endl;
}