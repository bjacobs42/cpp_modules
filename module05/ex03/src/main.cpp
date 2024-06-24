/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:14:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/22 20:43:25 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"

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

	Bureaucrat	carl;
	Bureaucrat	assistant("Jacob", 2);
	Bureaucrat	ezra("Ezra", 1);
	Intern		someLoser;
	AForm*		forms[3];

	forms[PARDON] = someLoser.makeForm("Presidential Pardon", "Carl");
	forms[SHRUBBERY] = someLoser.makeForm("Shrubbery Creation", "Office");
	forms[ROBOTOMY] = someLoser.makeForm("Robotomy Request", "Jacob");
	someLoser.makeForm("Make Music", "Music Box");
	std::cout << std::endl;

	assistant.executeForm(*forms[PARDON]);
	std::cout << std::endl;

	signForm(*forms[PARDON], ezra);
	signForm(*forms[PARDON], assistant);
	signForm(*forms[ROBOTOMY], carl);
	signForm(*forms[ROBOTOMY], assistant);
	signForm(*forms[SHRUBBERY], ezra);

	carl.executeForm(*forms[PARDON]);
	assistant.executeForm(*forms[PARDON]);
	std::cout << std::endl;

	ezra.executeForm(*forms[ROBOTOMY]);
	std::cout << std::endl;

	carl.executeForm(*forms[SHRUBBERY]);

	for (int i = 0; i < 3; ++i)
		delete forms[i];
	return (EXIT_SUCCESS);
}
