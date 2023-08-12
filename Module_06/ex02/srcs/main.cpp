/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/12 10:22:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generated(void) {
	const int random_index = std::rand() % 3;

	std::cout << random_index << std::endl;
	if (random_index == 0) {
		return new A;
	} else if (random_index == 1) {
		return new B;
	} else if (random_index == 2) {
		return new C;
	}
	return NULL;
}


void	identify(Base *p) {

	try {
		if (dynamic_cast<A *>(p))
			std::cout << "A";
		else if (dynamic_cast<B *>(p))
			std::cout << "B";
		else if (dynamic_cast<C *>(p))
			std::cout << "C";
		std::cout << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

// void	identify(Base &p) {

// }

int	main(void)
{
	Base *object = generated();

	identify(object);
	delete object;
	return (EXIT_SUCCESS);
}