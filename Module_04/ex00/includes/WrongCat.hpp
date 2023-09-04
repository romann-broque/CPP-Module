/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:29:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:42:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:

		// Constructors
			WrongCat();
			WrongCat(const WrongCat &wrongCat);
		// Overload assignment operator
			WrongCat& operator=(const WrongCat &wrongCat);
		// Destructor
			~WrongCat();
};