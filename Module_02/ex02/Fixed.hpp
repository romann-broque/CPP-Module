/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:04:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/22 15:15:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cmath>

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

	// Constructors
		Fixed();
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(const Fixed &fixed);
	// Destructor
		~Fixed();
	// Overload operator
		Fixed&	operator=(const Fixed &fixed);
	// Overload arithmetic operator
		float	operator+(const Fixed &nb) const;
		float	operator-(const Fixed &nb) const;
		float	operator*(const Fixed &nb) const;
		float	operator/(const Fixed &nb) const;
	// Overload comparaison operator
		bool	operator==(const Fixed &nb) const;
		bool	operator!=(const Fixed &nb) const;
		bool	operator<(const Fixed &nb) const;
		bool	operator<=(const Fixed &nb) const;
		bool	operator>(const Fixed &nb) const;
		bool	operator>=(const Fixed &nb) const;
	// Member functions
		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
	private:
		static const size_t	_fractPartSize = 8;
		int					_nb;
};

std::ostream&	operator<<(std::ostream &flux, Fixed const&fixed);

#endif