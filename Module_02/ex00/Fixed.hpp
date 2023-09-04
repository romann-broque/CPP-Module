/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:04:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:37:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <iostream>

// Colors

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define NC		"\033[0m"

#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class	Fixed
{
	public:

		Fixed();
		Fixed(Fixed const &fixed);
		~Fixed();
		Fixed& operator=(Fixed const &fixed);
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		static const size_t	_fractPartSize = 8;
		int					_nb;

};