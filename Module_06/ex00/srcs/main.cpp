/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/05 09:14:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printthis(const char c)
{
	std::cout << "Char: ";
	if (c > 126)
		std::cout << " Impossible";
	else if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	printthis(const int nb)
{
	std::cout << "Int: " << nb << std::endl;
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == 2)
	{
		printthis(ScalarConverter::convert<char>(av[1]));
		printthis(ScalarConverter::convert<int>(av[1]));
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}