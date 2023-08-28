/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 07:10:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/17 07:38:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class NotFound: public std::exception {

	public:
		const char *what() const throw();
};

template < template < typename, typename> class T>
typename T<int, std::allocator<int> >::iterator
	easyfind(T<int, std::allocator<int> > &container, const int nb);

#include "easyfind.tpp"