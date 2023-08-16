/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:33:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/16 13:21:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define NC		"\033[0m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	true
#endif

template<typename T>
class Array {

	private:

		T	*_dataArray;
		unsigned int _size;

	public:

		// Constructors
			Array();
			Array(const unsigned int n);
			Array(Array &array);
		// Overload assignement operator
			Array &operator=(Array &array);
		// Destructor
			~Array();
};

#include "Array.tpp"