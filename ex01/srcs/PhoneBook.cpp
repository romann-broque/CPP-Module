/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:01:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 15:02:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook destructor called" << std::endl;
}