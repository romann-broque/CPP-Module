/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:36:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/04 15:39:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

// #define EXPECTED_ARG_COUNT	2

class ScalarConverter{
public:
	template<typename T>
	static T convert(const std::string &);
private:
};
