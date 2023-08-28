// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   MutantStack.tpp                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/27 09:22:33 by rbroque           #+#    #+#             */
// /*   Updated: 2023/08/28 06:49:00 by rbroque          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {

	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< GREEN << "created (default)" << NC << std::endl;
	}
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &mutantStack): std::stack<T, Container>(mutantStack) {

	*this = mutantStack;
	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< GREEN << "created (copy)" << NC << std::endl;
	}
}

// Overload assignment operator

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &mutantStack) {

	if (this == &mutantStack)
		this->std::stack<T, Container>::operator=(mutantStack);
	return *this;
}

// Destructor

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
	if (PRINT_DEBUG) {
		std::cout << "MutantStack has been "
		<< RED << "destroyed" << NC << std::endl;
	}
}

// Iterator

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return std::stack<T, Container>::c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return std::stack<T, Container>::c.end();
}