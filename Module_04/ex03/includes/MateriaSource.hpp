/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:33:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 00:59:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

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

#endif