/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:33 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 17:03:58 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.cpp"
#include <iostream>

int main (void) {
	
	const Point	alpha(0, 0);
	const Point	beta(1, 1);
	const Point	charlie(2, 0);
	const Point	point(1, .5);

	std::cout << "alpha: x: " << alpha.getX() << ", y: " << alpha.getY() << std::endl
			  << "beta: x: " << beta.getX() << ", y: " << beta.getY() << std::endl
			  << "charlie: x: " << charlie.getX() << ", y: " << charlie.getY() << std::endl
			  << "point: x: " << point.getX() << ", y: " << point.getY() << std::endl;

	if (bsp(alpha, beta, charlie, point))
		std::cout << "Point is in the triangle!" << std::endl;
	else
		std::cout << "Point is not in the triangle!" << std::endl;
	return (EXIT_SUCCESS);
}
