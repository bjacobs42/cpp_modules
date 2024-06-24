/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:05:42 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 00:38:33 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

static int		getPrecisionLength(std::string convertee) {

	std::string::iterator	it;
	int						len;

	it = convertee.begin();
	while (*it != '.') {

		if (it == convertee.end())
			return (1);
		++it;
	}
	++it;
	len = 0;
	while (std::isdigit(*it)) {

		++len;
		++it;
	}
	return (len);
}

void	handleChar(const std::string& convertee) {

	unsigned char	c = static_cast<unsigned char>(convertee[0]);

	printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	printDouble(static_cast<double>(c), 3);
	printFloat(static_cast<float>(c), 3);
}

void	handleInt(const std::string& convertee) {

	int	i;
	int	len;

	try {
		i = std::stoi(convertee);
	}
	catch (std::out_of_range& e) {
		printImpossible();
		return;
	}
	if (i > std::numeric_limits<unsigned char>::max() || i < 0)
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(i));
	std::cout << "int: " << i << std::endl;
	len = getPrecisionLength(convertee);
	printDouble(static_cast<double>(i), len);
	printFloat(static_cast<float>(i), len);
}

void	handleDouble(const std::string& convertee) {

	double	d;
	int		len;

	try {
		d = std::stod(convertee);
	}
	catch (std::out_of_range& e) {
		printImpossible();
		return;
	}
	if (d > static_cast<double>(std::numeric_limits<unsigned char>::max()) || d < 0.0 || convertee == "nan")
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(d));
	if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()) || convertee == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	len = getPrecisionLength(convertee);
	printDouble(d, len);
	printFloat(static_cast<float>(d), len);
}

void	handleFloat(const std::string& convertee) {

	float	f;
	int		len;

	try {
		f = std::stof(convertee);
	}
	catch (std::out_of_range& e) {
		printImpossible();
		return;
	}
	if (f > static_cast<float>(std::numeric_limits<unsigned char>::max()) || f < 0.0f || convertee == "nanf")
		std::cout << "char: impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(f));
	if (f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()) || convertee == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	len = getPrecisionLength(convertee);
	if (f > static_cast<float>(std::numeric_limits<double>::max()) || f < static_cast<float>(std::numeric_limits<double>::min()))
		std::cout << "double: impossible" << std::endl;
	else
		printDouble(static_cast<double>(f), len);
	printFloat(f, len);
}
