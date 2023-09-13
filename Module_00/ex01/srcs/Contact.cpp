/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:09:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/13 11:00:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	if (PRINT_DEBUG)
		std::cout << "Contact default constructor called" << std::endl;
}

Contact::Contact(const std::string firstName,
	const std::string lastName, const std::string nickName,
	const std::string phoneNumber, const std::string darkestSecret):
	_firstName(firstName),
	_lastName(lastName),
	_nickName(nickName),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
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
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
	std::cout << GREEN << LIMIT_LINE << NC << std::endl;
}

void	Contact::set()
{
	if (!promptField("First Name: ", this->_firstName)
		&& !promptField("Last Name: ", this->_lastName)
		&& !promptField("Nickname: ", this->_nickName)
		&& !promptField("Phone Number: ", this->_phoneNumber)
		&& !promptField("Darkest secret: ", this->_darkestSecret))
		return;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getLastName() const
{
	return (this->_lastName);
}

std::string	Contact::getNickName() const
{
	return (this->_nickName);
}

bool	Contact::isComplete() const
{
	if (this->_firstName.empty() || this->_lastName.empty() ||
		this->_nickName.empty() || this->_phoneNumber.empty() ||
		this->_darkestSecret.empty())
		return (false);
	return (true);
}
