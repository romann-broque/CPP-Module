/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:59:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 16:36:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>
# include <string>

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG	false
# endif

class	Contact
{
	public:
		Contact();
		Contact(std::string firstName,
			std::string lastName, std::string nickName,
			std::string phoneNumber, std::string darkestSecret);
		~Contact();
		void display() const;
		void set();
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