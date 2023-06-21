/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:43:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/19 15:05:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	// Classic invocation

	Zombie	zombie1("Aaaarg");
	zombie1.announce();

	// Dynamic Invocation

	Zombie	*zombie3 = newZombie("Rhaaargh");
	zombie3->announce();
	delete zombie3;

	// Invocation in randomChump
	
	randomChump("Waaah");

	return (EXIT_SUCCESS);	
}