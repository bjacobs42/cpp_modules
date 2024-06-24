/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:36:37 by bjacobs           #+#    #+#             */
/*   Updated: 2024/05/14 20:28:38 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/utils.hpp"
#include <string>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& source) {

	*this = source;
};

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rightSide) {

	if (this != &rightSide)
		return (*this);
	return (*this);
}

static bool	somethingScientific(const std::string& number) {

	static std::string	allowedStrings[] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};

	for (int i = 0; i < 6; i++) {

		if (number == allowedStrings[i])
			return (true);
	}
	return (false);
}

static bool	initialParse(const std::string& number, int& dots, int& fNotation) {

	size_t	i = 0;

	if (!number[0])
		return (false);
	if (somethingScientific(number))
		return (++fNotation, true);
	if (number[0] == '-' || number[0] == '+')
		++i;
	while (number[i]) {

		if (number[i] == '.')
			++dots;
		else if (number[i] < '0' || number[i] > '9')
			break;
		++i;
	}
	if (number[i]) {

		if (number[i] == 'f' && !number[i + 1])
			++fNotation;
		else
			return (false);
	}
	if (dots > 1 || fNotation > 1)
		return (false);
	return (true);
}

static t_types	getType(const std::string& number) {

	int	dots = 0;
	int	fNotation = 0;

	if (number.length() == 1 && (number[0] < '0' || number[0] > '9'))
		return (CHAR);
	if (!initialParse(number, dots, fNotation))
		return (UNKNOWN);
	if (!dots && !fNotation)
		return (INT);
	if (!fNotation || number == "nan" || number == "+inf" || number == "-inf")
		return (DOUBLE);
	return (FLOAT);
}

void	ScalarConverter::convert(const std::string& convertee) {

	static void	(*functions[4])(const std::string& convertee) = {handleChar, handleInt, handleDouble, handleFloat};
	t_types		type;

	type = getType(convertee);
	if (type != UNKNOWN)
		functions[type](convertee);
	else
		printImpossible();
}
