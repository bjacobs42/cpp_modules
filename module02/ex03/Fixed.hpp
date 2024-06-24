/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:14:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:53:03 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class	Fixed {

	public:
		Fixed(void);
		Fixed(const Fixed & source);
		Fixed(const float & floatInt);
		Fixed(const int	& integer);
		~Fixed(void);

		bool					operator<(const Fixed & rightSide) const;
		bool					operator>(const Fixed & rightSide) const;
		bool					operator<=(const Fixed & rightSide) const;
		bool					operator>=(const Fixed & rightSide) const;
		bool					operator==(const Fixed & rightSide) const;
		bool					operator!=(const Fixed & rightSide) const;

		Fixed					operator-(const Fixed & rightSide) const;
		Fixed					operator+(const Fixed & rightSide) const;
		Fixed					operator*(const Fixed & rightSide) const;
		Fixed					operator/(const Fixed & rightSide) const;

		Fixed					operator++(void);
		Fixed					operator++(int);

		Fixed &					operator=(const Fixed & rightSide);

		int						getRawBits(void) const;
		void					setRawBits(const int & raw);

		int						toInt(void) const;
		float					toFloat(void) const;

		static Fixed &			min(Fixed & leftSide, Fixed & rightSide);
		static const Fixed &	min(const Fixed & leftSide, const Fixed & rightSide);

		static Fixed &			max(Fixed & leftSide, Fixed & rightSide);
		static const Fixed &	max(const Fixed & leftSide, const Fixed & rightSide);

	private:
		static const int		_factionalBits;
		int						_fixedInt;
};

std::ostream &					operator<<(std::ostream & outStream, const Fixed & rightSide);

#endif
