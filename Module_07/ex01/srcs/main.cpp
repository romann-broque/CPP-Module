/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/13 14:21:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void increase(int &nb)
{
	++nb;
}

static void toUpper(char &c) {

	c = toupper(c);
}

int main(void) {

	int		array_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char	array_char[8] = {"bonjour"};

	std::cout << "INT Array:" << std::endl;
	::iter(array_int, 10, display);
	::iter(array_int, 10, increase);
	::iter(array_int, 10, display);
	std::cout << "CHAR Array:" << std::endl;
	::iter(array_char, 7, display);
	::iter(array_char, 3, toUpper);
	::iter(array_char, 7, display);
	return 0;
}