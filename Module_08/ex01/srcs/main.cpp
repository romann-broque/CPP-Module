/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:48:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

	Span span1(4);

	span1.addNumber(1);
	span1.addNumber(15);
	span1.addNumber(10);
	span1.addNumber(-1);
	try {
		span1.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	span1.displaySpan();
	std::cout << "Shortest Span is : " << span1.shortestSpan() << std::endl;
	return 0;
}