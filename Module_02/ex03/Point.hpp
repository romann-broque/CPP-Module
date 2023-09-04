/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:59:01 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/23 14:55:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:

	// Constructors
		Point();
		Point(const float x_init, const float y_init);
		Point(Point &point);
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

#endif