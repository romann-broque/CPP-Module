/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:41:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/16 15:38:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

// Constructors

template <typename T>
Array<T>::Array(): _dataArray(new T[0]), _size(0) {

	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		GREEN << "created (default empty)" << NC << std::endl;
	}
}

template <typename T>
Array<T>::Array(const unsigned int n): _dataArray(new T[n]), _size(n) {

	for (unsigned int i = 0; i < _size; ++i)
		_dataArray[i] = 0;
	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		GREEN << "created (set)" << NC << std::endl;
	}
}

template <typename T>
Array<T>::Array(Array &array): _dataArray(new T[0]) {	
	*this = array;
	if (PRINT_DEBUG) {
		std::cout << "An Array has been " <<
		GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

template <typename T>
Array<T> &Array<T>::operator=(Array &array) {

	if (this != &array) { // Check for self-assignment
		delete[] _dataArray;
		_size = array._size;
		_dataArray = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			_dataArray[i] = array._dataArray[i];
		}
	}
	return *this;
}

// Overload access operator

template <typename T>
T &Array<T>::operator[](const unsigned int index) {

	if (index >= _size)
		throw InvalidIndexException();
	return _dataArray[index];
}

template <typename T>
const T &Array<T>::operator[](const unsigned int index) const {

	if (index >= _size)
		throw InvalidIndexException();
	return _dataArray[index];
}

// Member function

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
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

// Exceptions

template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw() {
	return "Invalid Index";
}