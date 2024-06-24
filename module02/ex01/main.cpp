/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:33 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/20 02:03:03 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main (void) {
	
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl
			  << "b is " << b << std::endl
			  << "c is " << c << std::endl
			  << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl
			  << "b is " << b.toInt() << " as integer" << std::endl
			  << "c is " << c.toInt() << " as integer" << std::endl
			  << "d is " << d.toInt() << " as integer" << std::endl;
	return (EXIT_SUCCESS);
}
