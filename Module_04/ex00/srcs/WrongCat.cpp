/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:30:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 17:31:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors

WrongCat::WrongCat()
{
	_type = "WrongCat";
	if (PRINT_DEBUG)
		std::cout << "WrongCat has been "
		<< GREEN <<  "created (default)" << NC
		<< std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal(wrongCat)
{
	*this = wrongCat;
	if (PRINT_DEBUG)
		std::cout << "WrongCat has been "
		<< GREEN <<  "created (copy)" << NC
		<< std::endl;
}

// Overload assignment operator

WrongCat&	WrongCat::operator=(const WrongCat &wrongCat)
{
	_type = wrongCat._type;
	return (*this);
}

// Destructor

WrongCat::~WrongCat()
{
	if (PRINT_DEBUG)
		std::cout << "WrongCat has been "
		<< RED <<  "destroyed" << NC
		<< std::endl;
}