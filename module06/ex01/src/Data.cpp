/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:26:55 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 01:54:03 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"


Data::Data(void) : _c('*'), _i(42), _d(42.42), _f(42.42f) {}
Data::Data(const char& c, const int& i, const double& d, const float& f) : _c(c), _i(i), _d(d), _f(f) {}
Data::Data(const Data& source) { *this = source; }
Data::~Data(void) {}

Data&	Data::operator=(const Data& rightSide) {

	_c = rightSide._c;
	_i = rightSide._i;
	_d = rightSide._d;
	_f = rightSide._f;
	return (*this);
}

char	Data::getChar(void) const {

	return (_c);
}

int	Data::getInt(void) const {

	return (_i);
}

double	Data::getDouble(void) const {

	return (_d);
}

float	Data::getFloat(void) const {

	return (_f);
}

std::ostream&	operator<<(std::ostream& outStream, const Data& rightSide) {

	outStream << "char: '" << rightSide.getChar() << "'" << ", int: " << rightSide.getInt()
			  << ", double: " << rightSide.getDouble() << ", float: " << rightSide.getFloat() << "f";
	return (outStream);
}
