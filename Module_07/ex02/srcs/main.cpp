/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/16 15:29:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {

	Array<int>	array1;
	Array<int>	array2(5);
	Array<int>	array3(array2);


	// Array 2 //
	std::cout << "Array 2" << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		try {array2[i] = i + 1;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	for (size_t i = 0; i < 10; ++i) {
		try {std::cout << array2[i] << std::endl;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	// Array 3 //
	std::cout << "Array 3" << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		try {std::cout << array3[i] << std::endl;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	array3 = array1;
	std::cout << "over!" << std::endl;
	return 0;
}