/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:53:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 10:26:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static size_t	getPriorityIndex(std::string level)
{
	static std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	size_t				index(0);

	while (index < LEVEL_COUNT && level != levels[index])
		++index;
	return (index);
}

static void	showHarl(Harl &harl, std::string arg)
{
	size_t	levelIndex(getPriorityIndex(arg));

	switch (levelIndex)
	{
		case 0:
			harl.complain("DEBUG");
			// Fall through
		case 1:
			harl.complain("INFO");
			// Fall through
		case 2:
			harl.complain("WARNING");
			// Fall through
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain("");
			break ;
		++levelIndex;
	}
}

int	main(int ac, char **av)
{
	int	exit_val(EXIT_FAILURE);

	if (ac == EXPECT_ARG_COUNT)
	{
		Harl	harl;

		showHarl(harl, av[1]);
		exit_val = EXIT_SUCCESS;
	}
	else
		std::cerr << "Usage: " << av[0] << " <FilterLevel>" << std::endl;
	return (exit_val);
}