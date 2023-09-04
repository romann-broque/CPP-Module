/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:09:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 13:41:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PRESIDENTIAL_NAME			"PresidentialPardonForm"
#define DEFAULT_PRESIDENT_TARGET	"Default_citizen"
#define PRESIDENT_SIGN_GRADE		25
#define PRESIDENT_EXEC_GRADE		5

class PresidentialPardonForm: public virtual AForm {

	private:

		std::string _target;
		void startExecution() const;
		PresidentialPardonForm();

	public:

		// Constructors
			PresidentialPardonForm(const std::string &target);
			PresidentialPardonForm(const PresidentialPardonForm &AForm);
		// Overload assignment operator
			PresidentialPardonForm& operator=(const PresidentialPardonForm &presidentialPardonForm);
		// Destructor
			~PresidentialPardonForm();
};