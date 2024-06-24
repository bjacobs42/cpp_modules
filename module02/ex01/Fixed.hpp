/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:14:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:50:48 by bjacobs          ###   ########.fr       */
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

		Fixed &	operator=(const Fixed & rightHandSide);

		int		getRawBits(void) const;
		void	setRawBits(const int & raw);

		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		static const int	_factionalBits;
		int					_fixedInt;
};

std::ostream & operator<<(std::ostream & outStream, const Fixed & rightHandSide);

#endif
