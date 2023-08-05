/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:04:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/08/05 09:27:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

template char ScalarConverter::convert(const std::string&);
template int ScalarConverter::convert(const std::string&);
template float ScalarConverter::convert(const std::string&);
template double ScalarConverter::convert(const std::string&);

static bool	isChar(const std::string &str) {
	return (str.length() == 1 && isdigit(str[0]) == false);
}

static bool	isSigned(const char c)
{
	return (c == '+' || c == '-');
}

static bool	isInt(const std::string &str) {

	if (str.length() == 0)
		return (false);
	for (size_t i = isSigned(str[0]); i < str.length(); ++i)	
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

template<typename T>T ScalarConverter::convert(const std::string &str)
{
	T result;

	if (isChar(str))
	{
		try {
			result = str[0];
			return (result);
		}
		catch(const std::exception& e) { return (-1); }
	}
	if (isInt(str))
	{
		try { result = atoi(str.c_str()); }
		catch(const std::exception& e) { return (-1); }
		return (result);
	}
	// if (std::is_same<T, float>::value)
	// {
	// 	float r;
	// 	try { r = std::stof(str); }
	// 	catch(const std::exception& e) { return (-1); }
	// 	return (r);
	// }
	// if (std::is_same<T, double>::value)
	// {
	// 	double r;
	// 	try { r = std::stod(str); }
	// 	catch(const std::exception& e) { return (-1); }
	// 	return (r);
	// }
	result = -1;
	return result;
}

