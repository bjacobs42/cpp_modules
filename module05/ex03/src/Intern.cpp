/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:34:56 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/22 21:15:57 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern(void) {

	//std::cout << "Default Intern constructor called" << std::endl;
};

Intern::~Intern(void) {

	//std::cout << "Intern deconstructor called" << std::endl;
};

Intern&	Intern::operator=(const Intern& source) {

	std::cout << "Intern copy assignment called... Which did nothing" << std::endl;
	if (this != &source)
		std::cout << "Damn you canonical form!!!" << std::endl;
	return (*this);
}

static void	ft_stol(std::string &s) {

	for (int i = 0; s[i]; i++)
		s[i] = std::tolower(s[i]);
}

static int	findForm(const std::string& formName) {

	std::string	formList[] = {"shrubbery creation", "presidential pardon", "robotomy request", ""};
	std::string	lowerCased;
	int			i;

	lowerCased = formName;
	ft_stol(lowerCased);
	for (i = 0; !formList[i].empty(); ++i) {

		if (lowerCased.find(formList[i]) != std::string::npos)
			return (i);
	}
	return (NOT_FOUND);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const {

	AForm*	newForm = NULL;
	int		caseNumber;

	caseNumber = findForm(formName);
	std::cout << "An intern created the " << formName << " Form";
	switch (caseNumber) {
	
		case SHRUBBERY:
			newForm = new ShrubberyCreationForm(target);
			break;

		case PARDON:
			newForm = new PresidentialPardonForm(target);
			break;

		case ROBOTOMY:
			newForm = new RobotomyRequestForm(target);
			break;

		default:
			std::cout << "... which doesn't exist";
			break;
	}
	std::cout << std::endl;
	return (newForm);
}
