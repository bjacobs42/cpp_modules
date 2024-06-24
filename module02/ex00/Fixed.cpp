/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:22:45 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:50:14 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_factionalBits = 8;

Fixed::Fixed(void) : _rawBits(0) {

	std::cout << "Default constructer called" << std::endl;
}

Fixed::Fixed(const Fixed & source) {

	std::cout << "Copy constructer called" << std::endl;
	*this = source;
}

Fixed::~Fixed(void) {

	std::cout << "Deconstructer called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & rightHandSide) {

	std::cout << "Assignment operator called" << std::endl;
	if (this != &rightHandSide)
		this->_rawBits = rightHandSide.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(const int & raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}
