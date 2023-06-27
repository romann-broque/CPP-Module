/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:21:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 15:02:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

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

#endif