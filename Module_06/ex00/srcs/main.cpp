/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/06 12:01:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// PRINT_THIS

void	printthis(const char c) {
	if (c > 127)
		std::cout << " Impossible";
	else if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	printthis(const int nb) {
	std::cout << nb << std::endl;
}

void	printthis(const float nb) {
	std::cout << nb << std::endl;
}

// PRINT_TYPE

void	printChar(const std::string &str) {
	std::cout << "Char: ";
	try {
		printthis(ScalarConverter::convert<char>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	printInt(const std::string &str) {
	std::cout << "Int: ";
	try {
		printthis(ScalarConverter::convert<int>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	printFloat(const std::string &str) {
	std::cout << "Float: ";
	try {
		printthis(ScalarConverter::convert<float>(str));
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_ARG_COUNT)
	{
		printChar(av[1]);
		printInt(av[1]);
		printFloat(av[1]);
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}