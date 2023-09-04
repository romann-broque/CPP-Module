/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:04:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:51:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include "ICharacter.hpp"

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

class	AMateria
{
	protected:
		std::string _type;

	public:

		// Constructors
			AMateria();
			AMateria(const AMateria &amateria);
			AMateria(std::string const &type);
		// Overload assignment operator
			AMateria& operator=(const AMateria &amateria);
		// Getter
			std::string const &getType() const;
		// Member functions
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter &target);
		// Destructor
			virtual ~AMateria();
};