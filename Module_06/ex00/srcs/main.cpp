/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/11 13:33:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "PrintNumber.hpp"

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
		PrintNumber::printChar(arg);
		PrintNumber::printInt(arg);
		PrintNumber::printFloat(arg);
		PrintNumber::printDouble(arg);
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}