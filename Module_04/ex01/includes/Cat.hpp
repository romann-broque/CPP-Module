/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:21:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:44:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat: public Animal
{
	public:

		// Constructors
			Cat();
			Cat(const Cat &cat);
		// Overload assignment operator
			Cat& operator=(const Cat &cat);
		// Member functions
			void	makeSound() const;
		// Destructor
			~Cat();

	private:

		// Attributes
			Brain	*_brain;
};