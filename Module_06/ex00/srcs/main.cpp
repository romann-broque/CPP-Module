/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/08 12:22:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// PRINT_THIS

void	printthis(const char c) {
	
	if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	printthis(const int nb) {
	std::cout << nb << std::endl;
}

void	printthis(const float nb) {

	std::cout << nb;
	(nb - floor(nb)) > 0.0f ? std::cout << "f" : std::cout << ".0f";
	std::cout << std::endl;
}

// PRINT_TYPE

void	printChar(const std::string &str) {
	std::cout << "char: ";
	try {
		printthis(ScalarConverter::convert<char>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	printInt(const std::string &str) {
	std::cout << "int: ";
	try {
		printthis(ScalarConverter::convert<int>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	printFloat(const std::string &str) {
	std::cout << "float: ";
	try {
		printthis(ScalarConverter::convert<float>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::string	trimSpaces(const std::string& str) {

	size_t start = str.find_first_not_of(WHITESPACES);
	if (start == std::string::npos) {return "";}

	size_t end = str.find_last_not_of(WHITESPACES);
	return str.substr(start, end - start + 1);
}

int	main(int ac, char **av)
{
	int	ret_val;
	std::string arg;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_ARG_COUNT)
	{
		arg = trimSpaces(av[1]);
		printChar(arg);
		printInt(arg);
		printFloat(arg);
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}