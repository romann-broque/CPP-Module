/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:01:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 17:21:19 by rbroque          ###   ########.fr       */
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

void	PhoneBook::rowFormat(std::string str) const
{
	static size_t	index = 1;

	if (str.length() > WIDTH)
		std::cout << str.substr(0, WIDTH - 1) << ".";
	else
		std::cout << std::setw(WIDTH) << str;
	if (index + 1 == ROW_NB)
	{
		std::cout << std::endl;
		index = 1;
	}
	else
	{
		std::cout << ROW_SEP;
		++index;
	}
}

void	PhoneBook::display_contact_list() const
{
	if (l_contactCount == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << std::left
		<< std::setw(WIDTH) << "Index" << ROW_SEP
		<< std::setw(WIDTH) << "First Name" << ROW_SEP
		<< std::setw(WIDTH) << "Last Name" << ROW_SEP
		<< std::setw(WIDTH) << "Nickname" << std::endl;
	for (size_t i(0); i < l_contactCount; ++i)
	{
		std::cout << std::left << std::setw(WIDTH) << i + 1 << ROW_SEP;
		rowFormat(l_contactList[i].getFirstName());
		rowFormat(l_contactList[i].getLastName());
		rowFormat(l_contactList[i].getNickName());
	}
}