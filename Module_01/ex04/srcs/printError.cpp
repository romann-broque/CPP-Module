/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printError.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:19:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 14:24:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mySed.hpp"

void	printError(char **av)
{
	std::string	progName = av[0];
	std::cout << "Usage: " << progName
		<< " <file> <pattern1> <pattern2>" << std::endl;
}