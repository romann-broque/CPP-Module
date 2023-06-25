/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:00:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 10:56:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		
		// Constructors
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &scavtrap);
		// Overload assignment operator
			ScavTrap& operator=(const ScavTrap &scavtrap);
		// Destructor
			~ScavTrap();

	private:
};

#endif