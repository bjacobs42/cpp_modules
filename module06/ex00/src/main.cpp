/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:04 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/02 01:06:37 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <ostream>
#include <string>

int	main(int ac, char **arg) {

	int	i;

	if (ac < 2)
		return (EXIT_SUCCESS);
	i = 1;
	while (true) {

		std::cout << "Input: " << arg[i] << std::endl
				  << "----------------------------------" << std::endl;
		ScalarConverter::convert(arg[i]);
		if (++i >= ac)
			break;
		std::cout << "----------------------------------" << std::endl;
	}
	return (EXIT_SUCCESS);
};
