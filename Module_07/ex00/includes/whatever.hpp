/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:54:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/13 13:11:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T&b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T &min(T &a, T&b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T &max(T &a, T&b)
{
	if (a < b)
		return b;
	return a;
}