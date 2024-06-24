/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:13:00 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 16:49:11 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// (bx - ax) * (py - ay) - (by - ay) * (px - ax) > 0 = right || < 0 = left
static Fixed	side(const Point alpha, const Point beta, const Point point) {

	return ((beta.getX() - alpha.getX()) * (point.getY() - alpha.getY()) - \
			(beta.getY() - alpha.getY()) * (point.getX() - alpha.getX()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point) {

	if (side(a, b, point) > 0) {

		if (side(b, c, point) > 0 && side(c, a, point) > 0)
			return (true);
	}
	else if (side(a, b, point) < 0) {

		if (side(b, c, point) < 0 && side(c, a, point) < 0)
			return (true);
	}
	return (false);
}
