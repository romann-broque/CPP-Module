/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:33:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 12:49:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class	MateriaSource: public IMateriaSource
{
	private:

		// Attributes
			AMateria	*_slots[INVENTORY_SIZE];
	public:

		// Constructors
			MateriaSource();
			MateriaSource(const MateriaSource &matSource);
		// Overload assignment operator
			MateriaSource& operator=(const MateriaSource &matSource);
		// Member functions
			void		learnMateria(AMateria*);
			AMateria*	createMateria(std::string const & type);
		// Destructor
			~MateriaSource();
};