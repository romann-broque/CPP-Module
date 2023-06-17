/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:09:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 15:28:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	if (PRINT_DEBUG)
		std::cout << "Contact default constructor called" << std::endl;
}

Contact::Contact(std::string firstName,
	std::string lastName, std::string nickName,
	std::string phoneNumber, std::string darkestSecret):
	l_firstName(firstName),
	l_lastName(lastName),
	l_nickName(nickName),
	l_phoneNumber(phoneNumber),
	l_darkestSecret(darkestSecret)
{
	if (PRINT_DEBUG)
		std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	if (PRINT_DEBUG)
		std::cout << "Contact destructor called" << std::endl;
}

void	Contact::display() const
{
	std::cout << "First Name: " << l_firstName << std::endl;
	std::cout << "Last Name: " << l_lastName << std::endl;
	std::cout << "Nickname: " << l_nickName << std::endl;
	std::cout << "Phone number: " << l_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << l_darkestSecret << std::endl;
}