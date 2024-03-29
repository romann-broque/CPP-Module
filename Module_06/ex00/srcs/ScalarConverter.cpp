/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:04:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/08/11 13:17:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

template char ScalarConverter::convert(const std::string&);
template int ScalarConverter::convert(const std::string&);
template float ScalarConverter::convert(const std::string&);
template double ScalarConverter::convert(const std::string&);

//		PRIVATE		//

// Check types

bool	ScalarConverter::isSigned(const char c)
{
	return (c == '+' || c == '-');
}

bool	ScalarConverter::isFloatNumber(const std::string str)
{
	const bool	sign = isSigned(str[0]);
	size_t		i;

	i = sign;
	while (str[i] && isdigit(str[i])){++i;}
	if (i - sign == 0 || str[i] != '.')
		return false;
	++i;
	while (str[i])
	{
		if (!isdigit(str[i]))
			break ;
		++i;
	}
	return ((str[i] == 'f')? str[i + 1] == '\0': str[i] == '\0');
}

bool	ScalarConverter::isChar(const std::string &str) {
	return (str.length() == 1 && isdigit(str[0]) == false);
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
	return (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff" || isFloatNumber(str));
}

bool	ScalarConverter::isDouble(const std::string &str) {
	return (str == "nan" || str == "+inf" || str == "inf" || str == "-inf" ||  isFloat(str));
}

template<typename T>T ScalarConverter::FromString(const std::string& str)
{
	std::istringstream ss(str);
	T ret;

	ss >> ret;
	if (ss.fail()) {
		if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
			ret = std::numeric_limits<T>::infinity();
		else if (str == "-inf" || str == "-inff")
			ret = -std::numeric_limits<T>::infinity();
		else if (str == "nan" || str == "nanf")
			ret = std::numeric_limits<T>::quiet_NaN();
		else
			throw ImpossibleConversionException();
	}
	return ret;
}

template<typename T, typename U>
U ScalarConverter::getConversion(const std::string &str) {

	U	result;

	result = FromString<U>(str);
	if (typeid(T) == typeid(char))
	{
		if (result < 0 || result > 127 || std::isnan(result))
			throw ScalarConverter::ImpossibleConversionException();
	}
	else if (typeid(T) == typeid(int))
	{
		if (result == std::numeric_limits<U>::infinity() || result == -std::numeric_limits<U>::infinity() || std::isnan(result))
			throw ScalarConverter::ImpossibleConversionException();
	}
	return (result);
}

template<typename T, typename U>
U ScalarConverter::tryConversion(const std::string &str){
	U	result;

	try {result = getConversion<T, U>(str);}
	catch(const std::exception& e) { throw ImpossibleConversionException();}
	return (result);
}

//		PUBLIC		//

// Convert

template<typename T>
T ScalarConverter::convert(const std::string &str)
{
	T result;

	if (isChar(str))
		result = tryConversion<T, char>(str);
	else if (isInt(str))
		result = tryConversion<T, int>(str);
	else if (isFloat(str))
		result = tryConversion<T, float>(str);
	else if (isDouble(str))
		result = tryConversion<T, double>(str);
	else
		throw ImpossibleConversionException();
	return (result);
}

// Exceptions

const char *ScalarConverter::ImpossibleConversionException::what() const throw () {
	return "impossible";
}
