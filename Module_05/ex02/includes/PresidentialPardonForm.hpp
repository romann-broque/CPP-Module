/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:09:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 09:12:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PRESIDENTIAL_NAME			"PresidentialPardonForm"
# define DEFAULT_PRESIDENT_TARGET	"Default_citizen"
# define PRESIDENT_SIGN_GRADE		25
# define PRESIDENT_EXEC_GRADE		5

class PresidentialPardonForm: public virtual AForm {

	private:

		std::string _target;
		void startExecution();
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

#endif