/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 11:46:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ScavTrap	scavbot("ScavBot");
	FragTrap	fragbot("FragBot");

	fragbot.attack("ScavBot");
	scavbot.takeDamage(30);
	scavbot.attack("FragBot");
	fragbot.takeDamage(20);
	fragbot.attack("ScavBot");
	scavbot.takeDamage(30);
	scavbot.attack("FragBot");
	fragbot.takeDamage(20);
	fragbot.attack("ScavBot");
	scavbot.takeDamage(30);
	scavbot.attack("FragBot");
	fragbot.takeDamage(20);
	fragbot.attack("ScavBot");
	scavbot.takeDamage(30);
	scavbot.attack("FragBot");
	fragbot.highFivesGuys();
	return (EXIT_SUCCESS);
}