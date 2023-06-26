/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:29:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/25 17:31:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

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

#endif