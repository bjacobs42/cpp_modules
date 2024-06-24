/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:19:57 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/02 06:23:18 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", 25, 5), _target("Aithel") {

	//std::cout << "PresidentialPardonForm Default Constructer Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardon", 25, 5), _target(target) {

	//std::cout << "PresidentialPardonForm Constructer Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm("PresidentialPardon", 25, 5) {

	this->_target = source._target;
	//std::cout << "PresidentialPardonForm Copy Constructer Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	//std::cout << "PresidentialPardonForm Deconstructer Called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {

	if (executor.getGrade() > this->getExecuteGrade()) {

		throw AForm::GradeTooLowException();
		return;
	}
	else if (!this->getIsSigned()) {

		throw AForm::FormNotSigned();
		return;
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox for their sins" << std::endl;
}
