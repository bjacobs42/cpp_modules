/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:14:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/11/10 18:50:27 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {

	public:
		Fixed(void);
		Fixed(const Fixed & source);
		~Fixed(void);

		Fixed &	operator=(const Fixed & rightHandSide);

		int		getRawBits(void) const;
		void	setRawBits(const int & raw);

	private:
		static const int	_factionalBits;
		int					_rawBits;
};

#endif
