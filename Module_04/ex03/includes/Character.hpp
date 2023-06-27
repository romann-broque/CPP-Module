/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:54:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/27 17:15:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE	4

class Character: public ICharacter
{
	private:

		// Attributes
			std::string _name;
			AMateria	*_inventory[INVENTORY_SIZE];

	public:

		// Constructors
			Character();
			Character(const std::string &name);
			Character(const Character &character);
		// Overload assignment operator
			Character& operator=(const Character &character);
		// Getter
			std::string const & getName() const;
		// Member functions
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
		// Destructor
			~Character();
};

#endif