/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:59:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/04 09:49:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point
{
	public:

	// Constructors
		Point();
		Point(const float x_init, const float y_init);
		Point(const Point &point);
	// Overload assignment operator
		Point&	operator=(const Point &point);
	// Member functions
		static float	getDeltaX(const Point &p1, const Point &p2);
		static float	getDeltaY(const Point &p1, const Point &p2);
	// Destructor
		~Point();

	private:

		const Fixed x;
		const Fixed y;
};
