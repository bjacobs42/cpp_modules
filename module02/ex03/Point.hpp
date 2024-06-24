/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:11:29 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 21:42:32 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point & source);
		~Point(void);

		Point &	operator=(const Point & rightSide);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

#endif // !POINT_HPP
