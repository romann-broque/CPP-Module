/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:34:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:16:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PhoneBook.hpp"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	false
#endif

#define PROMPT_MESSAGE	"Please enter a command: "

class Prompt
{
	public:
		Prompt();
		~Prompt();
		void	start();
	private:
		PhoneBook	phoneBook;
		void		addContact();
		void		searchContact() const;
};