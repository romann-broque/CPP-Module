/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/27 09:00:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

	// Classic Tests

	std::cout << BLUE << "CLASSIC TESTS" << NC << std::endl;

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
	
	std::cout << BLUE << "SHORTEST SPAN" << NC << std::endl;

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
	
	std::cout << BLUE << "LONGEST SPAN" << NC << std::endl;

	span3.addNumber(std::numeric_limits<long>::max() - 1);
	std::cout << span3.longestSpan() << std::endl;

	// Both

	std::cout << BLUE << "BOTH" << NC << std::endl;

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

	// Insertion

	std::cout << BLUE << "Insertion TESTS" << NC << std::endl;
	Span span5(100000);

	std::vector<long>::iterator begin = span5.begin();
	span5.insertBySize(begin, 5, 42);
	span5.display();
	std::vector<long>::iterator it2 = span5.begin() + 3;
	span5.insertBySize(it2, 5, 21);
	span5.display();
	try {
		std::vector<long>::iterator big_begin = span5.begin() + 1000000000;
		span5.insertBySize(big_begin, 5, 6);
	}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::vector<long>::iterator begin2 = span5.end();
	span5.insertBySize(begin2, 5, 6);
	span5.display();
	std::cout << span5.shortestSpan() << std::endl;
	std::cout << span5.longestSpan() << std::endl;
	
	std::vector<long>::iterator begin3 = span5.end();
	span5.insertByRange(begin3, -4, 5);
	span5.display();

	std::vector<long>::iterator begin4 = span5.begin() + 12;
	span5.insertByRange(begin4, 6, 1);
	span5.display();
	
	std::vector<long>::iterator begin5 = span5.begin() + 5;
	span5.insertByRange(begin5, 0, 0);
	span5.display();

	std::vector<long>::iterator begin6 = span5.begin();
	span5.insertByRange(begin6, -42, -36);
	span5.display();
	
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