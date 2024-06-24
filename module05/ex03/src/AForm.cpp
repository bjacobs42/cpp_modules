/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:52:43 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/22 19:06:36 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(void) : _name("No Music Law"), _signGrade(1), _executeGrade(3), _isSigned(false) {

	//std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade) : \
		_name(name), _signGrade(signGrade), _executeGrade(execGrade), _isSigned(false) {

	//std::cout << "AForm Constructor called" << std::endl;
	checkGrade(_signGrade);
	checkGrade(_executeGrade);
}

AForm::AForm(const AForm& source) : _name(source.getName()), _signGrade(source.getSignGrade()),\
									 _executeGrade(source.getExecuteGrade()), _isSigned(source.getIsSigned()) {

	//std::cout << "AForm Copy constructor called" << std::endl;
	checkGrade(_signGrade);
	checkGrade(_executeGrade);
}

AForm::~AForm(void) {

	//std::cout << "AForm Deconstructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& rightSide) {

	//std::cout << "AForm Assignment operator called" << std::endl;
	if (this != &rightSide) {

		_isSigned = rightSide.getIsSigned();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& outStream, const AForm& rightSide) {

	std::string	signedString;

	if (rightSide.getIsSigned())
		signedString = "true";
	else
		signedString = "false";
	outStream << rightSide.getName() << "Form; required grade to sign: " << rightSide.getSignGrade()
			  << ", required grade to execute: " << rightSide.getExecuteGrade()
			  << ", signed: " << signedString;
	return (outStream);
}

std::string	AForm::getName() const {

	return (_name);
}

int	AForm::getSignGrade() const {

	return (_signGrade);
}

int	AForm::getExecuteGrade() const {

	return (_executeGrade);
}

bool	AForm::getIsSigned() const {

	return (_isSigned);
}

void	AForm::beSigned(const Bureaucrat& signer) {

	if (signer.getGrade() > _signGrade) {

		signer.signForm(_name, false, "his Bureaucrat grade is too low");
		throw AForm::GradeTooLowException();
		return;
	}
	if (_isSigned) {

		signer.signForm(_name, false, "it was already signed");
	}
	else {

		_isSigned = true;
		signer.signForm(_name, true, "");
	}
}

void	AForm::execute(const Bureaucrat& executor) const {

	std::cout << executor.getName() << " tried to execute "
			  << _name << "Form, but " << _name
			  << " has nothing to execute" << std::endl;
}
