/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:57:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 16:04:16 by rbroque          ###   ########.fr       */
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