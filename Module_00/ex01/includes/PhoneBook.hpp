/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:18:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:16:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	false
#endif

#define WIDTH			10
#define CONTACT_MAX		8
#define ROW_SEP			" | "
#define ROW_NB			4

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

		Contact	_contactList[CONTACT_MAX];
		size_t	_contactCount;
		size_t	_contactLastIndex;
		void	printField(std::string str)const ;

};