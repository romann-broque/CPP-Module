/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:27:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/04 14:00:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
		
// Constructors
			
ScalarConverter::ScalarConverter(): _char(0), _int(0), _float(0), _double(0) {

	if (PRINT_DEBUG)
	{
		std::cout << "ScalarConverter has been " <<
		GREEN << "created (default)" << NC << std::endl;
	}
}

ScalarConverter::ScalarConverter(ScalarConverter &scalarConverter) {

	*this = scalarConverter;
	if (PRINT_DEBUG)
	{
		std::cout << "ScalarConverter has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignement operator

ScalarConverter &ScalarConverter::operator=(ScalarConverter &scalarConverter) {
	
	this->_char = scalarConverter._char;
	this->_int = scalarConverter._int;
	this->_float = scalarConverter._float;
	this->_double = scalarConverter._double;
	return *this;
}

// Destructor

ScalarConverter::~ScalarConverter() {

	if (PRINT_DEBUG)
	{
		std::cout << "ScalarConverter has been " <<
		RED << "deleted" << NC << std::endl;
	}
}
