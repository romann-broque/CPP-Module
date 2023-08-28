/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/28 06:13:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

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

// int main(void) {

// 	// Basic Tests

// 	MutantStack<int> stack;
// 	MutantStack<int> stack2(stack);
// 	std::stack<int> originalStack;

// 	stack.push(2);
// 	stack.push(2);
// 	stack.push(5);
	
// 	originalStack.push(2);
// 	originalStack.push(2);
// 	originalStack.push(5);

// 	std::cout << stack << std::endl;
// 	std::cout << originalStack << std::endl;

// 	// Iterator Test

// 	MutantStack<int>::iterator beginIt = stack.begin();
// 	MutantStack<int>::iterator endIt = stack.end();

// 	std::cout << *beginIt << std::endl;
// 	std::cout << *endIt << std::endl;

// 	return 0;
// }

// Initial Main

int main()
{
	// List 

	std::cout << BLUE << "List :" << NC << std::endl;

	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	std::cout << myList.back() << std::endl;
	myList.pop_back();
	std::cout << myList.size() << std::endl;
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);
	std::list<int>::iterator itList = myList.begin();
	std::list<int>::iterator iteList = myList.end();
	++itList;
	--itList;
	while (itList != iteList)
	{
	std::cout << *itList << std::endl;
	++itList;
	}
	// std::stack<int> s(mstack);
	
	std::cout << BLUE << "Mutant Stack :" << NC << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	// std::stack<int> s(mstack);
	return 0;
}