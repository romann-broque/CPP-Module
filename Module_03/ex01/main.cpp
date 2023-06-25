/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 11:19:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	clapbot("ClapBot");
	ScavTrap	scavbot("ScavBot");

	clapbot.attack("some creatures");
	scavbot.attack("Clapbot");
	clapbot.takeDamage(20);
	clapbot.takeDamage(20);
	clapbot.beRepaired(20);
	scavbot.attack("some creatures");
	scavbot.takeDamage(40);
	scavbot.beRepaired(30);
	scavbot.guardGate();
	scavbot.beRepaired(240);

	return (EXIT_SUCCESS);
}