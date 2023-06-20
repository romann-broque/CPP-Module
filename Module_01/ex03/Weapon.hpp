/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:27:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:20:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define NC		"\033[0m"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type);
		std::string const&getType() const;
	private:
		std::string	type;
};

#endif