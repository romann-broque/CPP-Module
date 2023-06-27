/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:23:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 14:31:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	Ice icecube;
	Ice *iceball = icecube.clone();
	Cure drugs;
	Cure *lsd = drugs.clone();

	std::cout << icecube.getType() << std::endl;
	std::cout << iceball->getType() << std::endl;
	std::cout << drugs.getType() << std::endl;
	std::cout << lsd->getType() << std::endl;
	delete lsd;
	delete iceball;
	return (EXIT_SUCCESS);
}