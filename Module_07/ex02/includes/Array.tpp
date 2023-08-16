/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:41:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/16 13:45:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

// Constructors

template <typename T>
Array<T>::Array(): _dataArray(new T[0]), _size(0) {

	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		GREEN << "created" << NC << std::endl;
	}
}

template <typename T>
Array<T>::Array(const unsigned int n): _dataArray(new T[n]), _size(n) {

	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		GREEN << "created" << NC << std::endl;
	}
}

template <typename T>
Array<T>::Array(Array &array) {	
	*this = array;
}

// Overload assignment operator

template <typename T>
Array<T> &Array<T>::operator=(Array &array) {

	if (this != &array) { // Check for self-assignment
		if (_size != array._size) {
			delete[] _dataArray;
			_size = array._size;
			_dataArray = new T[_size];
		}
		for (size_t i = 0; i < _size; ++i) {
			_dataArray[i] = array._dataArray[i];
		}
	}
	return *this;
}

// Destructor

template <typename T>
Array<T>::~Array() {

	delete[] this->_dataArray;
	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		RED << "deleted" << NC << std::endl;
	}
}