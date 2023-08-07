/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:36:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/06 12:56:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

#define EXPECTED_ARG_COUNT	2

class ScalarConverter{

	private:
	
	// Type Checker
		static bool isChar(const std::string &str);
		static bool isSigned(const char c);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
	// Type Getter
		template<typename T>
		static T FromString(const std::string& str);

	public:
		template<typename T>
		static T convert(const std::string &str);

	class ImpossibleConversionException: public std::exception {
		public :
			virtual const char* what() const throw();
	};
};
