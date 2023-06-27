/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:23:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 01:12:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

// int	main()
// {
// 	Character	joe("Joe");
// 	Character	marvin("Marvin");
// 	AMateria	*snowspell = new Ice;
// 	AMateria	*curespell = new Cure;

// 	joe.equip(snowspell);
// 	joe.use(0, marvin);
// 	joe.use(1, marvin);
// 	joe.equip(curespell);
// 	joe.use(1, marvin);
// 	marvin.use(0, joe);
// 	marvin.unequip(0);
// 	joe.use(0, marvin);
// 	joe.use(1, marvin);
// 	joe.unequip(0);
// 	joe.unequip(1);
// 	joe = marvin;
// 	for (size_t i(0); i < INVENTORY_SIZE; ++i)
// 	{
// 		joe.unequip(i);
// 		marvin.unequip(i);
// 	}
// 	delete snowspell;
// 	delete curespell;
// 	return (EXIT_SUCCESS);
// }

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}