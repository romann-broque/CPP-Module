/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:33:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 16:06:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	public:

		// Constructors
			Dog();
			Dog(const Dog &dog);
		// Overload assignment operator
			Dog& operator=(const Dog &dog);
		// Member functions
			void	makeSound() const;
		// Destructor
			~Dog();

	private:

		// Attributes
			Brain	*_brain;
};

#endif