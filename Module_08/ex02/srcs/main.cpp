/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 12:30:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, MutantStack<T> mutantStack){

	out << "Size: " << mutantStack.size() << std::endl;
	while (!mutantStack.empty()) {
		out << mutantStack.top() << std::endl;
		mutantStack.pop();
	}
	return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, std::stack<T> stack){

	out << "Size: " << stack.size() << std::endl;
	while (!stack.empty()) {
		out << stack.top() << std::endl;
		stack.pop();
	}
	return out;
}

int main(void) {

	MutantStack<int> stack;
	MutantStack<int> stack2(stack);
	std::stack<int> originalStack;

	stack.push(2);
	stack.push(2);
	stack.push(5);
	
	originalStack.push(2);
	originalStack.push(2);
	originalStack.push(5);

	std::cout << stack << std::endl;
	std::cout << originalStack << std::endl;
	return 0;
}