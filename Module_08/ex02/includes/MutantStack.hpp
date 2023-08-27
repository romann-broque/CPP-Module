/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:22:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 12:07:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[0;36m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

template <typename T>
class MutantStack {

	private:

		// Attributes
			std::stack<T> _stack;

	public:

		// Constructors
			MutantStack();
			MutantStack(MutantStack &mutantStack);
		// Overload assignment operator
			MutantStack &operator=(MutantStack &mutantStack);
		// Member
			void push(const T &value);
			void pop();
			T &top();
			const T &top() const;
			bool empty() const;
			size_t size() const;
		// Destructor
			~MutantStack();
};

#include "MutantStack.tpp"