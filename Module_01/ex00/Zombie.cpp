/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:43:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/19 13:08:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string given_name): name(given_name)
{
	std::cout << name << " has been "
		<< GREEN << "created" << NC << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been "
	<< RED << "destroyed" << NC << std::endl;
}

void	Zombie::announce() const
{
	std::cout << BLUE << name << NC
		<< YELLOW << ": BraiiiiiiinnnzzzZ..." << NC << std::endl;
}