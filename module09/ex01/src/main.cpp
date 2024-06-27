/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:10:33 by bjacobs           #+#    #+#             */
/*   Updated: 2024/06/27 20:42:29 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **argv) {
	RPN		rpn;
	double	result;

	if (ac < 2) {
		std::cout << "RPN: Usage: [equation]" << std::endl;
		return (EXIT_SUCCESS);
	}
	try {
		for (std::size_t i = 1; argv[i]; ++i)
			rpn.processArguments(argv[i]);
		result = rpn.getResult();
		std::cout << "Result: " << result << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: invalid :c" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
