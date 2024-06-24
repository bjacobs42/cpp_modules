/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:14:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/04 00:11:35 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int	main(void) {

	Bureaucrat	carl;
	Bureaucrat	ezra("Ezra", 1);
	Form		noMusic;
	Form		party("Constant Party Law", 125, 150);

	std::cout << noMusic << std::endl
			  << party << std::endl << std::endl;

	party.beSigned(ezra);
	party.beSigned(carl);
	try {
		noMusic.beSigned(carl);
	}
	catch (Form::GradeTooLowException& e) {

		std::cout << "Form exception: " << e.what() << std::endl << std::endl;
	}
	
	std::cout << noMusic << std::endl
			  << party << std::endl << std::endl;

	noMusic.beSigned(ezra);

	std::cout << noMusic << std::endl;
	return (EXIT_SUCCESS);
}
