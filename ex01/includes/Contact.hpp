/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:59:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:58:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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
		Contact(std::string firstName,
			std::string lastName, std::string nickName,
			std::string phoneNumber, std::string darkestSecret);
		~Contact();
		void set();
		void display() const;
		bool isComplete() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
	private:
		std::string	l_firstName;
		std::string	l_lastName;
		std::string	l_nickName;
		std::string	l_phoneNumber;
		std::string	l_darkestSecret;
};

#endif