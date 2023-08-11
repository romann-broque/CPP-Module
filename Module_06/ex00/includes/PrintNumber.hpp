/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintNumber.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:27:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/11 13:34:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ScalarConverter.hpp>

class PrintNumber{

	private:
	
		static void	printthis(const char c);
		static void	printthis(const int nb);
		static void	printthis(const float nb);
		static void	printthis(const double nb);

	public:

		static void	printChar(const std::string &str);
		static void	printInt(const std::string &str);
		static void	printFloat(const std::string &str);
		static void	printDouble(const std::string &str);
};
