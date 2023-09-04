/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:01:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:48:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): l_contactCount(0), l_contactLastIndex(0)
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
	if (contact.isComplete() == false)
	{
		std::cout << RED << "Contact is incomplete" << NC << std::endl;
		return ;
	}
	else
	{
		if (this->l_contactCount < CONTACT_MAX)
			this->l_contactCount++;
		if (this->l_contactLastIndex >= CONTACT_MAX)
			l_contactLastIndex = 0;
		this->l_contactList[l_contactLastIndex] = contact;
		l_contactLastIndex++;
	}
}

void	PhoneBook::printField(std::string str) const
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

void	PhoneBook::displayContact(const size_t index) const
{
	if (index >= l_contactCount)
	{
		std::cout << RED << "Invalid index" << NC << std::endl;
		return ;
	}
	l_contactList[index].display();
}

void	PhoneBook::displayContactList() const
{
	if (l_contactCount == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << std::left
		<< BLUE << std::setw(WIDTH) << "Index" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "First Name" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Last Name" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Nickname" << NC << std::endl;
	for (size_t i(0); i < l_contactCount; ++i)
	{
		std::cout << std::left << std::setw(WIDTH) << i << ROW_SEP;
		printField(l_contactList[i].getFirstName());
		printField(l_contactList[i].getLastName());
		printField(l_contactList[i].getNickName());
	}
}

bool	PhoneBook::isEmpty() const
{
	return (l_contactCount == 0);
}