/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:04:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/08/07 00:16:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <typeinfo>

template char ScalarConverter::convert(const std::string&);
template int ScalarConverter::convert(const std::string&);
template float ScalarConverter::convert(const std::string&);
template double ScalarConverter::convert(const std::string&);

//		PRIVATE		//

// Check types

bool	ScalarConverter::isChar(const std::string &str) {
	return (str.length() == 1 && isdigit(str[0]) == false);
}

bool	ScalarConverter::isSigned(const char c)
{
	return (c == '+' || c == '-');
}

bool	ScalarConverter::isInt(const std::string &str) {

	if (str.length() == 0)
		return false;
	for (size_t i = isSigned(str[0]); i < str.length(); ++i)	
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string &str) {

	size_t	i;

	i = 0;
	while (str[i] && isdigit(str[i])){++i;}
	if (str[i] != '.')
		return false;
	++i;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return false;
		++i;
	}
	return true;
}

template<typename T>T ScalarConverter::FromString(const std::string& str)
{
	std::istringstream ss(str);
	T ret;
	ss >> ret;
	return ret;
}

template<typename T, typename U>
U ScalarConverter::getConversion(const std::string &str) {

	U	result;

	result = FromString<U>(str);
	if (typeid(T) == typeid(char))
	{
		if (result < 0 || result > 127)
			throw ScalarConverter::ImpossibleConversionException();
	}	
	return (result);
}

//		PUBLIC		//

// Convert

template<typename T>
T ScalarConverter::convert(const std::string &str)
{
	T result;

	if (isChar(str))
	{
		try {result = getConversion<T, char>(str);}
		catch(const std::exception& e) { return (-1); }
	}
	if (isInt(str))
	{
		try {result = getConversion<T, int>(str);}
		catch(const std::exception& e) { return (-1); }
		return (result);
	}
	if (isFloat(str))
	{
		try {result = getConversion<T, float>(str);}
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
	throw ImpossibleConversionException();
	result = -1;
	return result;
}

// Exceptions

const char *ScalarConverter::ImpossibleConversionException::what() const throw () {
	return "Impossible";
}
