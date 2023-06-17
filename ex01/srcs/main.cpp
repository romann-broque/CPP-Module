/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:43:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/17 15:28:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	Contact	person1("Keanu", "Reeves", "John Wick", "010203040506", "He loves puppies");

	person1.display();
	return (EXIT_SUCCESS);
}