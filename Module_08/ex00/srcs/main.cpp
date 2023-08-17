/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/17 07:48:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

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

	// Vector //

	std::cout << "Vector" << std::endl; 
	size_t size = sizeof(array) / sizeof(array[0]);
	std::vector<int> numbers(array, array + size);

	printFirstOccurence(numbers, -1);
	printFirstOccurence(numbers, 8);
	printFirstOccurence(numbers, 19);
	return 0;
}