/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:33:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 15:07:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <cstdlib>
# include <string>
# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class	ClapTrap
{
	public:

		// Constructors
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &claptrap);
		// Overload assignment operator
			ClapTrap& operator=(const ClapTrap &claptrap);
		// Member functions
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
		// Destructor
			virtual	~ClapTrap();

	protected:

		// Attributes
			std::string	_name;
			size_t		_hitPoints;
			size_t		_energyPoints;
			size_t		_attackDamage;
};

#endif