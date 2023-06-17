/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:39:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/18 00:40:23 by rbroque          ###   ########.fr       */
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
