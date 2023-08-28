/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 03:00:39 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/08/28 07:59:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iostream>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[0;34m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG false
#endif

// MutantStack is a class which herits from the stack class
// where its elements are stored into another Container (here a double-ended-queue (deque))

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:

		// Constructors
			MutantStack();
			MutantStack(const MutantStack& mutantStack);
		// Overload assignment operator
			MutantStack& operator=(const MutantStack& other);
		// Destructor
			~MutantStack();
		// Iterator
			typedef typename std::stack<T, Container>::container_type::iterator iterator;
			iterator begin();
			iterator end();
};

#include "MutantStack.tpp"