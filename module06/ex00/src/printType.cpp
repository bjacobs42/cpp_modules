/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:06:13 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 00:34:28 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iomanip>
#include <iostream>

void	printImpossible(void) {

	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "double: impossible" << std::endl
		<< "float: impossible" << std::endl;
}

void	printChar(const unsigned char c) {

	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
}

void	printDouble(const double d, int precision) {

	std::cout << "double: ";
	if (std::isinf(d) && d > 0.0)
		std::cout << "+";
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(precision) << d << std::endl;
}
void	printFloat(const float f, int precision) {

	std::string	outStream;

	std::cout << "float: ";
	if (std::isinf(f) && f > 0.0f)
		std::cout << "+";
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(precision)
			  << f << "f" << std::endl;
}
