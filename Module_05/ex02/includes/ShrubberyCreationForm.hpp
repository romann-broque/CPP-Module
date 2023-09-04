/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:49:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 13:38:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_NAME				"ShrubberryCreationForm"
#define DEFAULT_SHRUBBERY_TARGET	"Default_Target"
#define SHRUBBERY_SIGN_GRADE		145
#define SHRUBBERY_EXEC_GRADE		137

class ShrubberyCreationForm: public virtual AForm {

	private:

		std::string _target;
		void startExecution() const;
		ShrubberyCreationForm();

	public:

		// Constructors
			ShrubberyCreationForm(const std::string &target);
			ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		// Overload assignment operator
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm &shrubberyCreationForm);
		// Destructor
			~ShrubberyCreationForm();
};