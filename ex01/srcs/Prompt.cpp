/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:57:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Prompt.hpp"

Prompt::Prompt()
{
	if (PRINT_DEBUG)
		std::cout << "Prompt constructor called" << std::endl;
}

Prompt::~Prompt()
{
	if (PRINT_DEBUG)
		std::cout << "Prompt destructor called" << std::endl;
}

void	Prompt::start()
{
	std::string	command;

	while (1)
	{
		std::cout << PROMPT_MESSAGE;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
	}
}

void	Prompt::addContact()
{
	Contact	contact;

	contact.set();
	phoneBook.addContact(contact);
}

void	Prompt::searchContact() const
{
	std::string	indexStr;

	if (phoneBook.isEmpty())
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	else
	{
		phoneBook.displayContactList();
		std::cout << "Contact index: ";
		std::getline(std::cin, indexStr);
		if (isStringDigits(indexStr) == false)
		{
			std::cout << RED << "Invalid input" << NC << std::endl;
			return ;
		}
		phoneBook.displayContact(getSizeTFromStr(indexStr));
	}
}