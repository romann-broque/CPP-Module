/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:22:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 09:33:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define NC		"\033[0m"
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[0;36m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

template <typename T>
class MutantStack {

	public:

		// Constructors
			MutantStack();
			MutantStack(MutantStack &mutantStack);
		// Overload assignment operator
			MutantStack &operator=(MutantStack &mutantStack);
		// Destructor
			~MutantStack();
};

#include "MutantStack.tpp"