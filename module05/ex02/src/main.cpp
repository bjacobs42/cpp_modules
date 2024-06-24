/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:14:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/22 19:26:15 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

static void	signForm(AForm& form, const Bureaucrat& person) {

	std::cout << form << std::endl;
	try {
		form.beSigned(person);
	}
	catch (AForm::GradeTooLowException& e) {

		std::cout << "Form exception: " << e.what() << std::endl;
	}
	std::cout << form << std::endl << std::endl;
}

int	main(void) {

	Bureaucrat				carl;
	Bureaucrat				assistant("Jacob", 2);
	Bureaucrat				ezra("Ezra", 1);
	PresidentialPardonForm	pardon("Carl");
	RobotomyRequestForm		robotism("Jacob");
	ShrubberyCreationForm	shrubs;

	assistant.executeForm(pardon);
	std::cout << std::endl;
	signForm(pardon, ezra);
	signForm(pardon, assistant);
	signForm(robotism, carl);
	signForm(robotism, assistant);
	signForm(shrubs, ezra);

	carl.executeForm(pardon);
	assistant.executeForm(pardon);
	std::cout << std::endl;
	ezra.executeForm(robotism);
	std::cout << std::endl;
	carl.executeForm(shrubs);
	return (EXIT_SUCCESS);
}
