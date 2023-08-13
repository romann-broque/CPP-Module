/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:33:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/13 14:21:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>
void iter(T *array, const size_t size, void (*function)(T &)) {
	for (size_t i = 0; i < size; ++i)
		function(array[i]);
}

template <typename T>
void display(T &object) {
	std::cout << object << std::endl;
}