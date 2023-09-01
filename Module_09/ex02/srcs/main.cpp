/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/01 07:10:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	try {
		PmergeMe	mergeMe(av + 1);
		// mergeMe.sort();
	}
	catch (std::exception &e) {
		// if (PRINT_DEBUG) {
			std::cout << "Error: " << e.what() << std::endl;
		// } else {
		// 	std::cout << "Error" << std::endl;
		// }
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}