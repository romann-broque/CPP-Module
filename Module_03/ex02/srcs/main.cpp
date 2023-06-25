/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 13:50:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ScavTrap	scavbot("ScavBot");
	FragTrap	fragbot("FragBot");

	fragbot.attack("Scavbot");
	scavbot.takeDamage(30);
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);
	fragbot.attack("Scavbot");
	scavbot.takeDamage(30);
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);
	fragbot.attack("Scavbot");
	scavbot.takeDamage(30);
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);
	scavbot.guardGate();
	scavbot.beRepaired(240);
	fragbot.highFivesGuys();
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);
	scavbot.attack("Fragbot");
	fragbot.takeDamage(20);

	return (EXIT_SUCCESS);
}