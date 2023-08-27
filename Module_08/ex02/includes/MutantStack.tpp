/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:22:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 09:34:35 by rbroque          ###   ########.fr       */
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
	(void)mutantStack;
	return *this;
}

// Destructor

template<typename T>
MutantStack<T>::~MutantStack() {
	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< RED << "destroyed" << NC << std::endl;
	}
}