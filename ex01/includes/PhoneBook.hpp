/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:18:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:58:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream>

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
		void displayContact(const size_t index) const;
		void displayContactList() const;
		bool isEmpty() const;
	
	private:

		Contact	l_contactList[CONTACT_MAX];
		size_t	l_contactCount;
		size_t	l_contactLastIndex;
		void	printField(std::string str)const ;

};

#endif