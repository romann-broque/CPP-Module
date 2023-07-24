/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:13:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/24 09:46:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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

class Bureaucrat {

	private:

		std::string name;
		size_t		grade;

	public:

		// Constructors
			Bureaucrat();
			Bureaucrat(const std::string &name, const size_t grade);
			Bureaucrat(const Bureaucrat &bureaucrat);
		// Overload assignment operator
			Bureaucrat& operator=(const Bureaucrat &bureaucrat);
		// Getter
			// std::string const & getName() const;
		// Destructor
			~Bureaucrat();
};

#endif