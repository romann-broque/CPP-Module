/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:33:00 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:52:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

#define GREY		"\033[0;30m"
#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BLUE		"\033[0;34m"
#define MAGENTA		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define NC			"\033[0m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class AMateria;

class ICharacter
{
	public:

		// Getter
			virtual std::string const & getName() const = 0;
		// Member functions
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
		// Destructor
			virtual ~ICharacter() {}
};