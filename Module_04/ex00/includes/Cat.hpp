/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:21:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 16:29:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

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

};

#endif