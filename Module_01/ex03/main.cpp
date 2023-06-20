/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:50:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:21:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int	main()
{
	Weapon	weapon("Sword");
	Weapon	weapon2("Big Weapon");

	std::string	weapon_name = weapon.getType();
	std::cout << "Got name: " << weapon_name << std::endl;
	weapon.setType("Big Axe");
	std::string newWeaponName = weapon.getType();
	std::cout << "Got name: " << newWeaponName << std::endl;
}