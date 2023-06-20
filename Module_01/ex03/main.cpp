/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:50:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 13:58:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon	weapon("Sword");
	Weapon	weapon2("Big Weapon");

	HumanA	joe("Joe", weapon);
	joe.attack();
	weapon.setType("Rockets");
	joe.attack();

	HumanB	zaphod("Zaphod");

	zaphod.attack();
	zaphod.setWeapon(weapon2);
	zaphod.attack();
	weapon2.setType("Zapper");
	zaphod.attack();

	return (EXIT_SUCCESS);
}