/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/25 19:23:21 by rbroque          ###   ########.fr       */
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
	span3.addNumber(0);
	std::cout << span3.shortestSpan() << std::endl;
	
	// Longest Span

	span3.addNumber(std::numeric_limits<long>::max() - 1);
	std::cout << span3.longestSpan() << std::endl;

	// Both

	Span span4(8);

	span4.addNumber(5);
	span4.addNumber(4);
	span4.addNumber(3);
	span4.addNumber(2);
	span4.addNumber(1);
	std::cout << span4.shortestSpan() << std::endl;
	std::cout << span4.longestSpan() << std::endl;
	span4.addNumber(5);
	std::cout << span4.shortestSpan() << std::endl;
	std::cout << span4.longestSpan() << std::endl;
	span4.addNumber(-2);
	std::cout << span4.shortestSpan() << std::endl;
	std::cout << span4.longestSpan() << std::endl;
	span4.addNumber(9);
	std::cout << span4.shortestSpan() << std::endl;
	std::cout << span4.longestSpan() << std::endl;

	// Big Test

	// Span span5(10000);

	return 0;
}


// MAIN FROM SUBJECT //

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }