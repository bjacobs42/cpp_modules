/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: bjacobs <bjacobs@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 19:00:42 by bjacobs       #+#    #+#                 */
/*   Updated: 2023/07/10 17:07:45 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <cctype>

/* -------------------- Util Functions -------------------- */

static int	emptyParse(const char *s) {

	if (!s)
		return (EXIT_FAILURE);
	for (int i = 0; s[i]; i++) {

		if (!isspace(s[i]))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

static	int	nameParse(const char *s) {

	if (emptyParse(s) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	for (int i = 0; s[i]; i++) {

		if ((s[i] >= '!' && s[i] <= '?' &&
			s[i] != '.' && s[i] != '\'' && s[i] != '-') || \
			(s[i] >= '[' && s[i] <= '`' && s[i] != '_')) {

			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	fillVar(std::string *var, const char *prompt, int (*parser)(const char *)) {

	while (true) {

		std::cout << prompt;
		if (!std::getline(std::cin, *var))
			return (0);
		if (parser((*var).data()) == EXIT_SUCCESS)
			return (1);
		std::cout << "Invalid input, try again" << std::endl;
	}
}

/* -------------------- Class Functions -------------------- */

int	Contact::initContact(void) {

	if (!fillVar(&this->name[FIRST], "Enter First Name: ", nameParse) \
		|| !fillVar(&this->name[LAST], "Enter Last Name: ", nameParse) \
		|| !fillVar(&this->name[NICK], "Enter Nickname: ", emptyParse) \
		|| !fillVar(&this->phoneNumber, "Enter phone number: ", emptyParse) \
		|| !fillVar(&this->darkSecret, "What is your darkest secret?: ", emptyParse)) {

		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
