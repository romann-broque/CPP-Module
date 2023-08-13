/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/13 12:25:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static	int	randNumber(const size_t min, const size_t max)
{
	srand(time(NULL));
	return ((rand() % max) + min);
}

Base	*generated(void) {

	const int random_index = randNumber(1, 3);

	if (random_index == 1) {
		return new A;
	} else if (random_index == 2) {
		return new B;
	} else if (random_index == 3) {
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

void	identify(Base &p) {

	try {
		if (dynamic_cast<A *>(&p))
			std::cout << "A";
		else if (dynamic_cast<B *>(&p))
			std::cout << "B";
		else if (dynamic_cast<C *>(&p))
			std::cout << "C";
		std::cout << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	Base *object1 = generated();

	identify(object1);
	identify(*object1);
	delete object1;
	return (EXIT_SUCCESS);
}