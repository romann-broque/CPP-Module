/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/04 13:59:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstdlib>
# include <iostream>

# define EXPECTED_ARG_COUNT	2

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

class ScalarConverter {

	private:

		// Attributes
		
			char	_char;
			int		_int;
			float	_float;
			double	_double;

	public:

		// Constructors
			
			ScalarConverter();
			ScalarConverter(ScalarConverter &scalarConverter);
		
		// Overload assignement operator
		
			ScalarConverter &operator=(ScalarConverter &scalarConverter);
		
		// Destructor

			~ScalarConverter();

};

#endif