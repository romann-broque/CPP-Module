/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/31 16:11:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	try {
		RPN	rpn(ac, av[1]);
		rpn.displayResult();
	}
	catch (std::exception &e) {
		if (PRINT_DEBUG) {
			std::cout << "Error: " << e.what() << std::endl;
		} else {
			std::cout << "Error" << std::endl;
		}
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}