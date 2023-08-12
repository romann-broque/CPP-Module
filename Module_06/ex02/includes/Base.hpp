/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 09:23:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/12 09:30:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

#define RED	"\033[0;31m"
#define NC	"\033[0m"
#ifndef PRINT_DEBUG
# define PRINT_DEBUG true
#endif

class Base {

	public:
		virtual ~Base();
};