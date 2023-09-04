/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:01:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:07:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _contactCount(0), _contactLastIndex(0)
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
		if (this->_contactCount < CONTACT_MAX)
			this->_contactCount++;
		if (this->_contactLastIndex >= CONTACT_MAX)
			_contactLastIndex = 0;
		this->_contactList[_contactLastIndex] = contact;
		_contactLastIndex++;
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
	if (index >= _contactCount)
	{
		std::cout << RED << "Invalid index" << NC << std::endl;
		return ;
	}
	_contactList[index].display();
}

void	PhoneBook::displayContactList() const
{
	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << std::left
		<< BLUE << std::setw(WIDTH) << "Index" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "First Name" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Last Name" << NC << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Nickname" << NC << std::endl;
	for (size_t i(0); i < _contactCount; ++i)
	{
		std::cout << std::left << std::setw(WIDTH) << i << ROW_SEP;
		printField(_contactList[i].getFirstName());
		printField(_contactList[i].getLastName());
		printField(_contactList[i].getNickName());
	}
}

bool	PhoneBook::isEmpty() const
{
	return (_contactCount == 0);
}