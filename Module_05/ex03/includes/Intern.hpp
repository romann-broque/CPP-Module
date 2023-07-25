/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:33:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 13:14:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define NC			"\033[0m"
# define FORM_KIND_COUNT 3

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class Intern {

	private:

		// Methods
			AForm *makeRobotomyRequestForm(const std::string &target);
			AForm *makePresidentialPardonForm(const std::string &target);
			AForm *makeShrubberyCreationForm(const std::string &target);
			
	public:

		// Constructors
			Intern();
			Intern(Intern const &intern);
		// Overload assignment operator
			Intern &operator=(Intern const &intern);
		// Member
			AForm *makeForm(const std::string &name, const std::string &target);
		// Destructor
			~Intern();
};

#endif