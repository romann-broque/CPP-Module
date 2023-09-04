/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:59:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:03:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>
# include <string>
# include "utils.hpp"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG	false
# endif

# define LIMIT_LINE		"<------------------------------------------------------------->"

class	Contact
{
	public:
		Contact();
		Contact(const std::string firstName,
			const std::string lastName, const std::string nickName,
			const std::string phoneNumber, const std::string darkestSecret);
		~Contact();
		void set();
		void display() const;
		bool isComplete() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};