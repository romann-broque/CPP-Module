/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:18:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 17:15:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG	false
# endif

# define WIDTH			10
# define CONTACT_MAX	8
# define ROW_SEP		" | "
# define ROW_NB			4

class	PhoneBook
{
	public:
		
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		void display_contact_list() const;
	
	private:

		Contact	l_contactList[CONTACT_MAX];
		size_t	l_contactCount;
		void	rowFormat(std::string str)const ;

};

#endif