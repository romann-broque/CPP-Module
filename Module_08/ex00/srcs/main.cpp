/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 09:30:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

template < template < typename, typename> class T>
static void printFirstOccurence(T<int, std::allocator<int> > &container, const int nb) {

	std::cout << nb << ": ";
	try {
		if (easyfind(container, nb) != container.end())
			std::cout << " Found!";
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << std::endl;
}

int main(void) {

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	// Vector //

	std::cout << "Vector" << std::endl; 
	std::vector<int> vectNumbers(array, array + size);

	printFirstOccurence(vectNumbers, -1);
	printFirstOccurence(vectNumbers, 8);
	printFirstOccurence(vectNumbers, 19);
	
	std::cout << std::endl; 
	
	// List //
	
	std::cout << "List" << std::endl; 
	std::list<int> listNumbers(array, array + size);

	printFirstOccurence(listNumbers, -1);
	printFirstOccurence(listNumbers, 8);
	printFirstOccurence(listNumbers, 19);
	return 0;
}