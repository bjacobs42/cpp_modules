/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:14:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/03 00:04:31 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main(void) {

	Bureaucrat	carl;
	Bureaucrat	ezra("Ezra", 3);

	try {
		Bureaucrat	unknown("Unknown", 300);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << carl << std::endl
			  << ezra << std::endl;
	try {
		ezra.incrementGrade(3);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << ", deincrementing to 1" << std::endl;
		ezra.deincrementGrade(ezra.getGrade() + -ezra.getGrade() + 1);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << ", incrementing to 150" << std::endl;
		ezra.deincrementGrade(ezra.getGrade() - 150);
	}

	std::cout << ezra << std::endl;

	try {
		carl.deincrementGrade(100);
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << ", deincrementing to 1" << std::endl;
		carl.deincrementGrade(carl.getGrade() + -carl.getGrade() + 1);
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << ", incrementing to 150" << std::endl;
		carl.incrementGrade(carl.getGrade() - 150);
	}
	std::cout << carl << std::endl;
	return (EXIT_SUCCESS);
}
