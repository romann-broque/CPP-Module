/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:55:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 00:19:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	if (PRINT_DEBUG)
		std::cout << "Harl has been "
			<< GREEN << "created" << NC << std::endl;
}

Harl::~Harl()
{
	if (PRINT_DEBUG)
		std::cout << "Harl has been "
			<< RED << "destroyed" << NC << std::endl;
}

void	Harl::complain(std::string level)
{
	static std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static LvlFunction	level_fct[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i(0); i < 4; ++i)
	{
		if (level == levels[i])
		{
			(this->*level_fct[i])();
			return ;
		}
	}
	std::cout << "Unknown level provided" << std::endl;
}

void	Harl::debug()
{
	std::cout << GREEN << DEBUG_MESSAGE << NC << std::endl;
}

void	Harl::info()
{
	std::cout << BLUE << INFO_MESSAGE << NC << std::endl;
}

void	Harl::warning()
{
	std::cout << YELLOW << WARNING_MESSAGE << NC << std::endl;
}

void	Harl::error()
{
	std::cout << RED << ERROR_MESSAGE << NC << std::endl;
}