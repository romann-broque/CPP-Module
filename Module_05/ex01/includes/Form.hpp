/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:37:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 15:04:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define DEFAULT_NAME	"Random"
# define DEFAULT_SIGN_GRADE	150
# define DEFAULT_EXEC_GRADE	150

# define GREY		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define NC			"\033[0m"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class Form {

	private:

		//Attributes
			std::string _name;
			size_t		_isSigned;
			size_t		_signGrade;
			size_t		_execGrade;
		// Utils
			void assignGrade(size_t &dest, const size_t src);

	public:

		// Constructors
			Form();
			Form(const std::string &name, const size_t signGrade, const size_t execGrade);
			Form(const Form &form);
		// Overload assignment operator
			Form& operator=(const Form &bureaucrat);
		// Getter
			std::string const &getName() const;
			size_t getSignGrade() const;
			size_t getExecGrade() const;
			bool isSigned() const;
		// Destructor
			~Form();
		// Exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// Overload outstream operator
std::ostream& operator<<(std::ostream& outStream, Form &form);

#endif