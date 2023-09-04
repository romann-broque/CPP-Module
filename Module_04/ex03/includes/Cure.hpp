/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:28:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:51:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

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