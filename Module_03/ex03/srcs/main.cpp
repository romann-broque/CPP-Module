/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 15:48:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	dbot0;
	DiamondTrap	dbot1("Dbot");
	DiamondTrap	dbot2(dbot1);
	DiamondTrap	dbot3("Great Giga Chad");

	dbot0.whoAmI();
	dbot0.attack("Gorogu");
	dbot1.whoAmI();
	dbot1.attack("Gorogu");
	dbot2.whoAmI();
	dbot2.attack("Gorogu");
	dbot0 = dbot3;
	dbot0.whoAmI();
	dbot0.attack("Gorogu");
	
	return (EXIT_SUCCESS);
}