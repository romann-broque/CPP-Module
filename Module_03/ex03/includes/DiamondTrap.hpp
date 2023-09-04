/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:55:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 15:20:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// Constructors
			DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(const DiamondTrap &diamondTrap);
		// Overload assignment operator
			DiamondTrap& operator=(const DiamondTrap &diamondtrap);
		// Member functions
			void	attack(const std::string& target);
			void	whoAmI();
		// Destructor
			~DiamondTrap();

	private:

		// Attributes
		std::string	_name;
};

#endif