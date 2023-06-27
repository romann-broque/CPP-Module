/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:02:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 14:18:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:

		// Constructors
			Ice();
			Ice(const Ice &ice);
			Ice(std::string const &type);
		// Overload assignment operator
			Ice& operator=(const Ice &ice);
		// Getter
			std::string const &getType() const;
		// Member functions
			Ice* clone() const;
			// virtual void use(ICharacter &target);
		// Destructor
			~Ice();
};

#endif