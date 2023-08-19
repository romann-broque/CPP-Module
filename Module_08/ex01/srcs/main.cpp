/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 11:04:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

	// Classic Tests

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

	// Shortest Span

	Span span2(42);

	try {
		size_t shortestSpan = span2.shortestSpan();
		std::cout << "Shortest Span is : " << shortestSpan << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	span2.addNumber(-1);
	try {
		size_t shortestSpan = span2.shortestSpan();
		std::cout << "Shortest Span is : " << shortestSpan << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	span2.addNumber(80);
	try {
		size_t shortestSpan = span2.shortestSpan();
		std::cout << "Shortest Span is : " << shortestSpan << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	Span span3(42);

	span3.addNumber(std::numeric_limits<long>::min());
	span3.addNumber(std::numeric_limits<long>::max());
	std::cout << span3.shortestSpan() << std::endl;
	span3.addNumber(std::numeric_limits<long>::min());
	std::cout << span3.shortestSpan() << std::endl;
	
	// Longest Span

	std::cout << span3.longestSpan() << std::endl;

	return 0;
}