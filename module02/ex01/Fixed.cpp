/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:22:45 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:51:14 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_factionalBits = 8;

/* --------------- [ De/Constructer Functions ] --------------- */
Fixed::Fixed(void) : _fixedInt(0) {

	std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(const float & floatInt) : \
		_fixedInt(roundf(floatInt * (1 << this->_factionalBits))) {

	std::cout << "Float constructer called" << std::endl;
}

Fixed::Fixed(const int & integer) : _fixedInt(integer << this->_factionalBits) {

	std::cout << "Integer constructer called" << std::endl;
}

Fixed::Fixed(const Fixed & source) {

	std::cout << "Copy constructer called" << std::endl;
	*this = source;
}

Fixed::~Fixed(void) {

	std::cout << "Deconstructer called" << std::endl;
}

/* --------------- [ Operator Functions ] --------------- */

Fixed &	Fixed::operator=(const Fixed & rightHandSide) {

	std::cout << "Assignment operator called" << std::endl;
	if (this != &rightHandSide)
		this->_fixedInt = rightHandSide.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & outStream, const Fixed & rightHandSide) {

	outStream << rightHandSide.toFloat();
	return (outStream);
}

/* --------------- [ Public Functions ] --------------- */

int	Fixed::getRawBits(void) const {

	return (this->_fixedInt);
}

void	Fixed::setRawBits(const int & raw) {

	this->_fixedInt = raw;
}

int	Fixed::toInt(void) const {

	return (this->_fixedInt >> this->_factionalBits);
}

float	Fixed::toFloat(void) const {

	return ((float)this->_fixedInt / (float)(1 << this->_factionalBits));
}
