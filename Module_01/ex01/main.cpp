/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:43:07 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/19 15:00:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	int		hordeSize = 10;
	Zombie *horde = zombieHorde(hordeSize, "Arrgh");

	for (int i = 0; i < hordeSize; ++i)
		horde[i].announce();
	delete[] horde;
}