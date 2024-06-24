/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:33 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/20 18:10:42 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main (void) {
	
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	c(42.42f);
	Fixed const	d(c);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl
			  << "b is " << b << std::endl
			  << "c is " << c << std::endl
			  << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl
			  << "b is " << b.toInt() << " as integer" << std::endl
			  << "c is " << c.toInt() << " as integer" << std::endl
			  << "d is " << d.toInt() << " as integer" << std::endl;

	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else if (a < b)
		std::cout << "a is less than b" << std::endl;
	if (b == d)
		std::cout << "b is equal to d" << std::endl;
	else if (b != d)
		std::cout << "b is not equal to d" << std::endl;

	std::cout << "a * d equals " << (a * d) << std::endl
			  << "a + c equals " << (a + c) << std::endl
			  << "d - b equals " << (d - b) << std::endl
			  << "a - c equals " << (a - c) << std::endl
			  << "a / c equals " << (a / c) << std::endl;

	std::cout << "a is " << a << std::endl
			  << "prefix increment " << ++a << std::endl
			  << "postfix increment " << a++ << std::endl
			  << "a is " << a << std::endl;

	std::cout << "max value between " << a << " and " << c << " is " << Fixed::max(a, c) << std::endl
			  << "min value between " << b << " and " << c << " is " << Fixed::max(b, c) << std::endl;
	return (EXIT_SUCCESS);
}
