/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:10:33 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/23 06:24:24 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **argv) {
	RPN	rpn;

	if (ac < 2) {
		std::cout << "RPN: Usage: [numbers] [...]" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (std::size_t i = 1; argv[i]; ++i) {
		if (!rpn.processArguments(argv[i]))
			return (EXIT_FAILURE);
	}
	try {
		std::cout << "Result: " << rpn.getResult() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: invalid :c" << std::endl;
	}
	return (EXIT_SUCCESS);
}
