/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:31:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 11:34:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
	public:

		// Constructors
			FragTrap();
			FragTrap(std::string name);
			FragTrap(const FragTrap &fragtrap);
		// Overload assignment operator
			FragTrap& operator=(const FragTrap &fragtrap);
		// Member functions
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			void	highFivesGuys();
		// Destructor
			~FragTrap();
};

#endif