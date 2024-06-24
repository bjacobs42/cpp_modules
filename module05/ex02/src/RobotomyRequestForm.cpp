/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:19:57 by bjacobs           #+#    #+#             */
/*   Updated: 2024/04/09 23:37:04 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), _target("Ezra") {

	//std::cout << "RobotomyRequestForm Default Constructer Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45), _target(target) {

	//std::cout << "RobotomyRequestForm Constructer Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm("RobotomyRequest", 72, 45) {

	this->_target = source._target;
	//std::cout << "RobotomyRequestForm Copy Constructer Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	//std::cout << "RobotomyRequestForm Deconstructer Called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {

	int	rng;

	if (executor.getGrade() > this->getExecuteGrade()) {

		throw AForm::GradeTooLowException();
		return;
	}
	else if (!this->getIsSigned()) {

		throw AForm::FormNotSigned();
		return;
	}
	std::srand(std::time(NULL));
	rng = std::rand() % 2;
	std::cout << "* Drilling Noises *" << std::endl
			  << "* Cranking Noises *" << std::endl;
	switch (rng) {

		case 0:
			std::cout << "* Screaming Noises *" << std::endl
				<< _target << "'s robotomization has failed" << std::endl;
			break;

		default:
			std::cout << "* Banging Noises *" << std::endl
				<< _target << " has been robotomized" << std::endl;
			break;
	}
}
