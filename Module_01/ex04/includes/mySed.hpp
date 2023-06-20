/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mySed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:13:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/20 14:43:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSED_HPP
# define MYSED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

# define EXPECT_ARG_COUNT	3

int		mySed(std::string filename, std::string pattern1, std::string pattern2);
void	printError(char **av);

#endif