/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:33:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 14:16:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
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

#endif