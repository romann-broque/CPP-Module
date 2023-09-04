/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:33:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:35:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:
		
		// Constructors
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap &FragTrap);
		// Overload assignment operator
			FragTrap& operator=(const FragTrap &FragTrap);
		// Member functions
			void	highFivesGuys();
		// Destructor
			~FragTrap();
};