/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:34:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 16:36:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_HPP
# define PROMPT_HPP

# include "PhoneBook.hpp"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG	false
# endif
# define PROMPT_MESSAGE	"Please enter a command: "

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

#endif