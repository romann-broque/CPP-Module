/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:39:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/13 11:00:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Colors

#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define BLUE		"\033[0;34m"
#define NC			"\033[0m"

// Status

#define VALID_LINE		0
#define INVALID_LINE	1

typedef int t_line_status;

t_line_status	getMyLine(std::string &line);
size_t			getSizeTFromStr(std::string &str);
bool			isStringDigits(const std::string &str);
t_line_status	promptField(const std::string &prompt, std::string &field);
