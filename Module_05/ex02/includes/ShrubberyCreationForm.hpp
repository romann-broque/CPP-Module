/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:49:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 23:08:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define SHRUBBERY_NAME	"ShrubberryCreationForm"
# define DEFAULT_TARGET	"Default_Target"

class ShrubberyCreationForm: public virtual AForm {

	private:

		std::string _target;
		void startExecution();
		ShrubberyCreationForm();

	public:

		// Constructors
			ShrubberyCreationForm(const std::string &target);
			ShrubberyCreationForm(const ShrubberyCreationForm &AForm);
		// Overload assignment operator
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		// Destructor
			~ShrubberyCreationForm();
};

#endif