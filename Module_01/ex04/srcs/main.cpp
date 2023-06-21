/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:12:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 14:36:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mySed.hpp"

int	main(int ac, char **av)
{
	int			exit_val = EXIT_FAILURE;

	if (ac - 1 != EXPECT_ARG_COUNT)
		printError(av);
	else
		exit_val = mySed(av[1], av[2], av[3]);
	return (exit_val);
}
