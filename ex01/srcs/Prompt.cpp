/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:36:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 16:30:50 by rbroque          ###   ########.fr       */
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

	while (command != "EXIT")
	{
		std::cout << PROMPT_MESSAGE;
		std::getline(std::cin, command);
		if (command == "ADD")
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
	phoneBook.display_contact_list();
}