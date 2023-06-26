/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:57:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 15:47:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	// std::cout << BLUE << "---DOGS---" << NC << std::endl;

	// Dog		dog;
	// Dog		dog2;
	// Dog		*dog3 = new Dog();

	// std::cout << dog.getType() << std::endl;
	// std::cout << dog2.getType() << std::endl;
	// std::cout << dog3->getType() << std::endl;
	// dog.makeSound();
	// dog = dog2;
	// dog.makeSound();
	// dog2.makeSound();
	// Dog		dog4(*dog3);	
	// dog4.makeSound();
	// delete dog3;

	// std::cout << BLUE << "---CATS---" << NC << std::endl;

	// Cat		cat;
	// Cat		cat2;
	// std::cout << cat.getType() << std::endl;
	// std::cout << cat2.getType() << std::endl;
	// cat2 = cat;
	// cat.makeSound();
	// cat2.makeSound();

///////////////////////////////////////////////////////////////////////////////////

	std::cout << BLUE << "---HOME---" << NC << std::endl;

	Animal	*home[10];

	for (size_t i(0); i < 10; ++i)
	{
		if (i < 5)
			home[i] = new Dog();
		else
			home[i] = new Cat();
	}
	for (size_t i(0); i < 10; ++i)
		delete home[i];
	return (EXIT_SUCCESS);
}