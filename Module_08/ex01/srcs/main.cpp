/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/26 08:14:26 by rbroque          ###   ########.fr       */
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

	Span span5(100000);

	std::vector<long>::iterator begin = span5.begin();
	span5.insertNumber(begin, 10, 42);

	// std::vector<long> numbers;
	// std::vector<long>::iterator begin = numbers.begin();

	// for (std::vector<long>::iterator it = begin; it != begin + 5; ++it) {
	// 	std::cout << "Test Insertion" << std::endl;
	// 	numbers.insert(it, 56);
	// }

	// std::vector<long>::iterator big_end = begin + 1000000000;
	// span5.insertNumber(begin, big_end, 42);
	// std::cout << span5.shortestSpan() << std::endl;
	// std::cout << span5.longestSpan() << std::endl;
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