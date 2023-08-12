/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 08:24:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/12 09:09:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
	std::string name;
	size_t		id;
};

class Serializer {

	public:

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

};