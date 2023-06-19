/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:39:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:57:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Prompt.hpp"

size_t	getSizeTFromStr(std::string &str)
{
	std::istringstream iss(str);
	size_t result(0);

	iss >> result;
	return (result);
}

bool	isStringDigits(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}