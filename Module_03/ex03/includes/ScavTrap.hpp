/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:00:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:37:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		
		// Constructors
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &scavtrap);
		// Overload assignment operator
			ScavTrap& operator=(const ScavTrap &scavtrap);
		// Member functions
			void	attack(const std::string& target);
			void	guardGate();
		// Destructor
			~ScavTrap();
};