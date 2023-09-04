/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:20:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 13:38:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

#define ROBOTOMY_NAME			"RobotomyRequestForm"
#define DEFAULT_ROBOT_TARGET	"Default_Robot"
#define ROBOT_SIGN_GRADE		72
#define ROBOT_EXEC_GRADE		45

class RobotomyRequestForm: public virtual AForm {

	private:

		std::string _target;
		void startExecution() const;
		RobotomyRequestForm();

	public:

		// Constructors
			RobotomyRequestForm(const std::string &target);
			RobotomyRequestForm(const RobotomyRequestForm &aForm);
		// Overload assignment operator
			RobotomyRequestForm& operator=(const RobotomyRequestForm &robotomyRequestForm);
		// Destructor
			~RobotomyRequestForm();
};