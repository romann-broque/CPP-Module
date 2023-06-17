/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:01:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 15:50:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): l_contactCount(0)
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::addContact(Contact contact)
{
	if (this->l_contactCount < CONTACT_MAX)
	{
		this->l_contactList[this->l_contactCount] = contact;
		this->l_contactCount++;
	}
	else
		std::cout << "PhoneBook is full" << std::endl;
}

void	PhoneBook::display_contact_list() const
{
	for (size_t i(0); i < l_contactCount; ++i)
		l_contactList[i].display();
}