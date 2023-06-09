/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:09:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:59:18 by rbroque          ###   ########.fr       */
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
	std::cout << GREEN << LIMIT_LINE << NC << std::endl;
	std::cout << "First Name: " << l_firstName << std::endl;
	std::cout << "Last Name: " << l_lastName << std::endl;
	std::cout << "Nickname: " << l_nickName << std::endl;
	std::cout << "Phone number: " << l_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << l_darkestSecret << std::endl;
	std::cout << GREEN << LIMIT_LINE << NC << std::endl;
}

void	Contact::set()
{
	std::cout << "First Name: ";
	std::getline(std::cin, this->l_firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, this->l_lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->l_nickName);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->l_phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->l_darkestSecret);
}

std::string	Contact::getFirstName() const
{
	return (this->l_firstName);
}

std::string	Contact::getLastName() const
{
	return (this->l_lastName);
}

std::string	Contact::getNickName() const
{
	return (this->l_nickName);
}

bool	Contact::isComplete() const
{
	if (this->l_firstName.empty() || this->l_lastName.empty() ||
		this->l_nickName.empty() || this->l_phoneNumber.empty() ||
		this->l_darkestSecret.empty())
		return (false);
	return (true);
}