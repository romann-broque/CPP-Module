/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:22:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 12:29:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors

template<typename T>
MutantStack<T>::MutantStack() {

	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< GREEN << "created (default)" << NC << std::endl;
	}
};

template<typename T>
MutantStack<T>::MutantStack(MutantStack &mutantStack) {

	*this = mutantStack;
	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< GREEN << "created (copy)" << NC << std::endl;
	}
};

// Overload assignment operator

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> &mutantStack) {

	if (this != &mutantStack) {
		_stack = mutantStack._stack;
	}
	return *this;
}

// Member

template<typename T>
void MutantStack<T>::push(const T &value) {
	_stack.push(value);
}

template<typename T>
void MutantStack<T>::pop() {
	_stack.pop();
}

template<typename T>
T &MutantStack<T>::top() {
	return _stack.top();
}

template<typename T>
const T &MutantStack<T>::top() const {
	return _stack.top();
}

template<typename T>
bool MutantStack<T>::empty() const {
	return _stack.empty();
}

template<typename T>
size_t MutantStack<T>::size() const {
	return _stack.size();
}

// Destructor

template<typename T>
MutantStack<T>::~MutantStack() {
	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< RED << "destroyed" << NC << std::endl;
	}
}