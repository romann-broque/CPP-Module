/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:04:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/19 15:18:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

int	main()
{
	std::string	niceStr = "HI THIS IS BRAIN";
	std::string	*stringPTR = &niceStr;
	std::string	&stringREF = niceStr;

	std::cout << &niceStr << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << niceStr << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (EXIT_SUCCESS);
}