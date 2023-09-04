/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:27:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:20:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string given_type): type(given_type)
{
	if (PRINT_DEBUG)
		std::cout << type << " has been "
			<< GREEN << "created" << NC << std::endl;
}

Weapon::~Weapon()
{
	if (PRINT_DEBUG)
		std::cout << type << " has been "
			<< RED << "destroyed" << NC << std::endl;
}

std::string	const&Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string newType)
{
	type = newType;
}