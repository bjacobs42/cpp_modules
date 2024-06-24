/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:22:45 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:52:12 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_factionalBits = 8;

/* --------------- [ De/Constructer Functions ] --------------- */
Fixed::Fixed(void) : _fixedInt(0) {

	//std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(const float & floatInt) : \
		_fixedInt(roundf(floatInt * (1 << this->_factionalBits))) {

	//std::cout << "Float constructer called" << std::endl;
}

Fixed::Fixed(const int & integer) : _fixedInt(integer << this->_factionalBits) {

	//std::cout << "Integer constructer called" << std::endl;
}

Fixed::Fixed(const Fixed & source) {

	//std::cout << "Copy constructer called" << std::endl;
	*this = source;
}

Fixed::~Fixed(void) {

	//std::cout << "Deconstructer called" << std::endl;
}

/* --------------- [ Operator Functions ] --------------- */

Fixed &	Fixed::operator=(const Fixed & rightSide) {

	//std::cout << "Assignment operator called" << std::endl;
	if (this != &rightSide)
		this->_fixedInt = rightSide.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed & rightSide) const {

	return (this->_fixedInt < rightSide.getRawBits());
}

bool	Fixed::operator>(const Fixed & rightSide) const {

	return (this->_fixedInt > rightSide.getRawBits());
}

bool	Fixed::operator<=(const Fixed & rightSide) const {

	return (this->_fixedInt <= rightSide.getRawBits());
}

bool	Fixed::operator>=(const Fixed & rightSide) const {

	return (this->_fixedInt >= rightSide.getRawBits());
}

bool	Fixed::operator==(const Fixed & rightSide) const {

	return (this->_fixedInt == rightSide.getRawBits());
}

bool	Fixed::operator!=(const Fixed & rightSide) const {

	return (this->_fixedInt != rightSide.getRawBits());
}

Fixed	Fixed::operator-(const Fixed & rightSide) const {

	Fixed	result;

	result.setRawBits(this->_fixedInt - rightSide.getRawBits());
	return (result);
}

Fixed	Fixed::operator+(const Fixed & rightSide) const {

	Fixed	result;

	result.setRawBits(this->_fixedInt + rightSide.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed & rightSide) const {

	Fixed	result;

	result.setRawBits((this->_fixedInt * rightSide.getRawBits()) >> this->_factionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed & rightSide) const {

	Fixed	result;

	result.setRawBits((this->_fixedInt << this->_factionalBits) / rightSide.getRawBits());
	return (result);
}

Fixed	Fixed::operator++(void) {

	++this->_fixedInt;
	return (*this);
}

Fixed	Fixed::operator++(int) {

	Fixed	result;

	result.setRawBits(this->_fixedInt);
	++this->_fixedInt;
	return (result);
}

std::ostream &	operator<<(std::ostream & outStream, const Fixed & rightSide) {

	outStream << rightSide.toFloat();
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

Fixed &	Fixed::min(Fixed & leftSide, Fixed & rightSide) {

	if (leftSide < rightSide)
		return (leftSide);
	return (rightSide);
}

const Fixed &	Fixed::min(const Fixed & leftSide, const Fixed & rightSide) {

	if (leftSide < rightSide)
		return (leftSide);
	return (rightSide);
}

Fixed &	Fixed::max(Fixed & leftSide, Fixed & rightSide) {

	if (leftSide > rightSide)
		return (leftSide);
	return (rightSide);
}

const Fixed &	Fixed::max(const Fixed & leftSide, const Fixed & rightSide) {

	if (leftSide > rightSide)
		return (leftSide);
	return (rightSide);
}
