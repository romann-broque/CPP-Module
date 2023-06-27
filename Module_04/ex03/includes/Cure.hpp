/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:28:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 16:25:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:

		// Constructors
			Cure();
			Cure(const Cure &ice);
			Cure(std::string const &type);
		// Overload assignment operator
			Cure& operator=(const Cure &ice);
		// Getter
			std::string const &getType() const;
		// Member functions
			Cure* clone() const;
			void use(ICharacter &target);
		// Destructor
			~Cure();
};

#endif