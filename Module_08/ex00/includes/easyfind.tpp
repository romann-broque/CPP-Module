/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 07:10:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/17 07:40:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"

const char *NotFound::what() const throw() {
	return "Number not found";
}

template < template < typename, typename> class T>
typename T<int, std::allocator<int> >::iterator
	easyfind(T<int, std::allocator<int> > &container, const int nb) {

	typename T<int, std::allocator<int> >::iterator itpos;
	if ((itpos = std::find(container.begin(), container.end(), nb)) != container.end())
		return itpos;
	throw NotFound();
}