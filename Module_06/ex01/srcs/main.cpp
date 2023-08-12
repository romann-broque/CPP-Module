/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/12 09:15:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data data = {
		.name = "John",
		.id = 0,
	};
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Ptr -> " << ptr << std::endl;

	Data *data_recovered = Serializer::deserialize(ptr);
	std::cout << "Data Recovered -> name = " << data_recovered->name
		<< "; id = " << data_recovered->id << std::endl;

	data.name = "Jack";
	data.id = 42;
	
	std::cout << "Data Recovered -> name = " << data_recovered->name
		<< "; id = " << data_recovered->id << std::endl;
	
	uintptr_t ptr2 = Serializer::serialize(&data);
	std::cout << "Ptr -> " << ptr2 << std::endl;
	
	Data *data_recovered2 = Serializer::deserialize(ptr2);
	std::cout << "Data Recovered -> name = " << data_recovered2->name
		<< "; id = " << data_recovered2->id << std::endl;

	return (EXIT_SUCCESS);
}