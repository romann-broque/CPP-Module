/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:39:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:18:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Colors

#define RED			"\033[0;31m"
#define GREEN		"\033[0;32m"
#define BLUE		"\033[0;34m"
#define NC			"\033[0m"

size_t	getSizeTFromStr(std::string &str);
bool	isStringDigits(const std::string &str);
