/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:48:44 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:44:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define BRAIN_SIZE	100

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

class	Brain
{
	public:

		// Constructors
			Brain();
			Brain(const Brain &brain);
		// Overload assignment operator
			Brain& operator=(const Brain &brain);
		// Destructor
			~Brain();

	private:

		// Attributes
			std::string _ideas[BRAIN_SIZE];
};