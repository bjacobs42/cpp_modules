/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:50:24 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 16:56:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0) {

	// std::cout << "Default constructer called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {

	// std::cout << "Float constructer called" << std::endl;
}

Point::Point(const Point & source) {

	// std::cout << "Copy constructer called" << std::endl;
	*this = source;
}

Point::~Point(void) {

	// std::cout << "Deconstructer called" << std::endl;
}

Point &	Point::operator=(const Point & rightSide) {

	// std::cout << "Assignment operator called" << std::endl;
	if (this != &rightSide) {

		this->_x = rightSide.getX();
		this->_y = rightSide.getY();
	}
	return (*this);
}

Fixed	Point::getX(void) const {

	return (this->_x);
}

Fixed	Point::getY(void) const {

	return (this->_y);
}
