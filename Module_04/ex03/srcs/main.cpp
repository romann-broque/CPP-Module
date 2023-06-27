/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:23:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 17:27:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main()
{
	Character	joe("Joe");
	AMateria	*snowspell = new Ice;

	joe.equip(snowspell);
	// joe.equip(snowspell);
	return (EXIT_SUCCESS);
}