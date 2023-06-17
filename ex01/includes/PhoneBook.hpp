/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:18:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 15:22:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG	false
# endif

# define CONTACT_MAX	8

class	PhoneBook
{
	public:
		
		PhoneBook();
		~PhoneBook();
	
	private:

		Contact	repertory[CONTACT_MAX];
};

#endif