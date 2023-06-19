/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:00:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/16 11:55:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#define NO_ARG_PROVIDED	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static std::string	toUpperString(std::string str)
{
	for (size_t i(0); i < str.length(); ++i)
		str[i] = toupper(str[i]);
	return (str);
}

int main(int ac, char **av)
{
	--ac;
	++av;
	if (ac == 0)
		std::cout << NO_ARG_PROVIDED;
	for (int i(0); i < ac; ++i)
	{
		std::string	arg(av[i]);
		std::cout << toUpperString(arg);
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}