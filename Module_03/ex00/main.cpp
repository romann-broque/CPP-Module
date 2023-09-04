/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 15:37:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	bot("Box");

	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.attack("some creatures");
	bot.takeDamage(8);
	bot.attack("some creatures");
	bot.beRepaired(5);
	bot.beRepaired(5);
	bot.beRepaired(5);
	bot.takeDamage(18);
	bot.takeDamage(20);
	bot.beRepaired(5);
	bot.beRepaired(5);
	bot.attack("void");
	
	return (EXIT_SUCCESS);
}