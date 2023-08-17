/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/17 06:58:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {

	Array<int>			int_array1;
	Array<int>			int_array2(5);
	Array<int>			int_array3(int_array2);

	// Int Array 2 //
	std::cout << "Array 2" << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		try {int_array2[i] = i + 1;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	for (size_t i = 0; i < 10; ++i) {
		try {std::cout << int_array2[i] << std::endl;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	// Int Array 3 //
	std::cout << "Array 3" << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		try {std::cout << int_array3[i] << std::endl;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	std::cout << "Array 1 size: " << int_array1.size()  << std::endl;
	std::cout << "Array 2 size: " << int_array2.size()  << std::endl;
	std::cout << "Array 3 size: " << int_array3.size()  << std::endl;
	int_array3 = int_array1;
	std::cout << "Array 3 size: " << int_array3.size()  << std::endl;
	
	/// STRING ///

	Array<std::string>	char_array(3);
	std::cout << "Array STRING" << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		try {char_array[i] = "Hello Agent " + i;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	for (size_t i = 0; i < 10; ++i) {
		try {std::cout << char_array[i] << std::endl;}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	std::cout << "It's over!" << std::endl;
	return 0;
}