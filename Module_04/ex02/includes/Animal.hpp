/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:58:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/26 16:01:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <cstdlib>
# include <string>
# include <iostream>

# define GREY		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class	Animal
{
	public:

		// Constructors
			Animal();
			Animal(const Animal &animal);
		// Overload assignment operator
			Animal& operator=(const Animal &animal);
		// Member functions
			virtual void makeSound() const = 0;
		// Getter
			std::string	getType() const;
		// Destructor
			virtual ~Animal();

	protected:

		// Attributes
			std::string	_type;
};

#endif