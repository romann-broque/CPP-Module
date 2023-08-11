/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintNumber.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:28:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/11 13:32:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintNumber.hpp"

// PRINT_THIS

void	PrintNumber::printthis(const char c) {
	
	if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	PrintNumber::printthis(const int nb) {
	std::cout << nb << std::endl;
}

void	PrintNumber::printthis(const float nb) {

	std::cout << nb;
	if (nb != std::numeric_limits<float>::infinity() && nb != -std::numeric_limits<float>::infinity()
		&& (nb - floor(nb)) <= 0.0f)
			std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	PrintNumber::printthis(const double nb) {

	std::cout << nb;
	if (nb != std::numeric_limits<double>::infinity() && nb != -std::numeric_limits<double>::infinity()
		&& (nb - floor(nb)) <= 0.0f)
			std::cout << ".0";
	std::cout << std::endl;
}

// PRINT_TYPE

void	PrintNumber::printChar(const std::string &str) {
	std::cout << "char: ";
	try {
		printthis(ScalarConverter::convert<char>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	PrintNumber::printInt(const std::string &str) {
	std::cout << "int: ";
	try {
		printthis(ScalarConverter::convert<int>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	PrintNumber::printFloat(const std::string &str) {
	std::cout << "float: ";
	try {
		printthis(ScalarConverter::convert<float>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	PrintNumber::printDouble(const std::string &str) {
	std::cout << "double: ";
	try {
		printthis(ScalarConverter::convert<double>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
