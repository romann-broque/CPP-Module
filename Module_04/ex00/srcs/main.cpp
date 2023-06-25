/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:57:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 17:35:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	Animal		creature;
	WrongAnimal	wrongCreature;
	WrongCat	wrongCat;
	Cat		cat;
	Dog		dog;

	std::cout << creature.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << wrongCreature.getType() << std::endl;
	std::cout << wrongCat.getType() << std::endl;
	creature.makeSound();
	cat.makeSound();
	dog.makeSound();
	wrongCreature.makeSound();
	wrongCat.makeSound();
}