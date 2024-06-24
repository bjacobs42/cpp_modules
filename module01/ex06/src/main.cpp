/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:17:17 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/15 21:02:03 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

static int	getLevel(std::string levelString) {

	std::string	levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level;

	for (level = 0; level <= ERROR; level++) {

		if (levelString == levelList[level])
			return (level);
	}
	return (-1);
}

static void	filter(std::string levelString, Harl&	harl) {

	int	level;

	level = getLevel(levelString);
	switch (level) {
	
		case DEBUG:
			harl.complain("DEBUG");
			[[fallthrough]];

		case INFO:
			harl.complain("INFO");
			[[fallthrough]];

		case WARNING:
			harl.complain("WARNING");
			[[fallthrough]];

		case ERROR:
			harl.complain("ERROR");
			break;

		default:
			std::cout << DEFAULT_MSG << std::endl;
	}
}

int main (int ac, char **av) {
	
	Harl	harl;

	if (ac != 2)
		std::cout << DEFAULT_MSG << std::endl;
	else
		filter(av[1], harl);
	return (EXIT_SUCCESS);
}
