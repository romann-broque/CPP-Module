/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:36:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/11 13:15:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <typeinfo>
#include <iomanip>
#include <limits>

#define	WHITESPACES			" \t\r\n"
#define EXPECTED_ARG_COUNT	2

class ScalarConverter{

	private:
	
	// Type Checker
		static bool isSigned(const char c);
		static bool	isFloatNumber(const std::string str);
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
	// Type Getter
		template<typename T>
		static T FromString(const std::string& str);
		template<typename T, typename U>
		static U getConversion(const std::string &str);
		template<typename T, typename U>
		static U tryConversion(const std::string &str);

	public:
		template<typename T>
		static T convert(const std::string &str);

	class ImpossibleConversionException: public std::exception {
		public :
			virtual const char* what() const throw();
	};
};
