/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/15 21:11:36 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include <iostream>
#include <string>

/* --------------- [ Util Functions ] --------------- */

static void	printComplaint(std::string level, std::string message) {

	std::cout << level << message << std::endl
			  << std::endl;
}

/* --------------- [ Private Functions ] --------------- */

void	Harl::error(void) {

	printComplaint("[ ERROR ]", ERROR_MSG);
}

void	Harl::warning(void) {

	printComplaint("[ WARNING ]", WARNING_MSG);
}

void	Harl::info(void) {

	printComplaint("[ INFO ]", INFO_MSG);
}

void	Harl::debug(void) {

	printComplaint("[ DEBUG ]", DEBUG_MSG);
}

/* --------------- [ Public Functions ] --------------- */

void	Harl::complain(std::string level) {

	void		(Harl::*complainFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levelMsgs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i <= ERROR; i++) {

		if (level == levelMsgs[i]) {

			(this->*complainFunctions[i])();
			break;
		}
	}
}
