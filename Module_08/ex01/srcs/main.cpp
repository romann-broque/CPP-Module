/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:15:59 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/19 10:04:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

	Span span1(4);

	span1.addNumber(1);
	span1.addNumber(15);
	span1.addNumber(10);
	span1.addNumber(-1);
	span1.addNumber(14);
	span1.displaySpan();
	return 0;
}