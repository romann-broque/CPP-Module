/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:41:58 by rbroque          ###   ########.fr       */
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

class	WrongAnimal
{
	public:

		// Constructors
			WrongAnimal();
			WrongAnimal(const WrongAnimal &wronganimal);
		// Overload assignment operator
			WrongAnimal& operator=(const WrongAnimal &wronganimal);
		// Member functions
			void	makeSound() const;
		// Getter
			std::string	getType() const;
		// Destructor
			~WrongAnimal();

	protected:

		// Attributes
			std::string	_type;
};