/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:54:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:23:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

// Colors

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define NC		"\033[0m"

// Messages

#define DEBUG_MESSAGE		"This is a debug"
#define INFO_MESSAGE		"This is an information"
#define WARNING_MESSAGE		"This is a warning"
#define ERROR_MESSAGE		"This is an error"

#define LEVEL_COUNT		4

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class	Harl
{
	public:

		Harl();
		~Harl();
		void complain(std::string level);

	private:

		void debug();
		void info();
		void warning();
		void error();
};

typedef void (Harl::*LvlFunction)(void);