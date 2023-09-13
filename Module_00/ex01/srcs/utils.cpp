/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:39:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/13 11:01:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Prompt.hpp"

size_t	getSizeTFromStr(std::string &str) {
	std::istringstream iss(str);
	size_t result(0);

	iss >> result;
	return (result);
}

bool	isStringDigits(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

t_line_status	getMyLine(std::string &line) {

	t_line_status	isLineValid;

	isLineValid = VALID_LINE;
	std::getline(std::cin, line);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		isLineValid = INVALID_LINE;
	}
	return isLineValid;
}

t_line_status	promptField(const std::string &prompt, std::string &field) {
	std::cout << prompt;
	return getMyLine(field);
}
