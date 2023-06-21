/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:04:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/21 14:41:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <cstdlib>
# include <iostream>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define NC		"\033[0m"

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG true
# endif

class	Fixed
{
	public:

		Fixed();
		Fixed(Fixed &fixed);
		~Fixed();
		Fixed& operator=(Fixed &fixed);
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		static const size_t	_fractPartSize = 8;
		int					_nb;

};

#endif