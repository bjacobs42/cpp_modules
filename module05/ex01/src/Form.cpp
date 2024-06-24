/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:52:43 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/04 00:16:15 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(void) : _name("No Music Law"), _signGrade(1), _executeGrade(3), _isSigned(false) {

	//std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int& signGrade, const int& execGrade) : \
		_name(name), _signGrade(signGrade), _executeGrade(execGrade), _isSigned(false) {

	//std::cout << "Form Constructor called" << std::endl;
	checkGrade(_signGrade);
	checkGrade(_executeGrade);
}

Form::Form(const Form& source) : _name(source.getName()), _signGrade(source.getSignGrade()),\
									 _executeGrade(source.getExecuteGrade()), _isSigned(source.getIsSigned()) {

	//std::cout << "Form Copy constructor called" << std::endl;
	checkGrade(_signGrade);
	checkGrade(_executeGrade);
}

Form::~Form(void) {

	//std::cout << "Form Deconstructor called" << std::endl;
}

Form&	Form::operator=(const Form& rightSide) {

	//std::cout << "Form Assignment operator called" << std::endl;
	if (this != &rightSide) {

		_isSigned = rightSide.getIsSigned();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& outStream, const Form& rightSide) {

	std::string	signedString;

	if (rightSide.getIsSigned())
		signedString = "true";
	else
		signedString = "false";
	outStream << rightSide.getName() << " form; required grade to sign: " << rightSide.getSignGrade()
			  << ", required grade to execute: " << rightSide.getExecuteGrade()
			  << ", signed: " << signedString;
	return (outStream);
}

std::string	Form::getName() const {

	return (_name);
}

int	Form::getSignGrade() const {

	return (_signGrade);
}

int	Form::getExecuteGrade() const {

	return (_executeGrade);
}

bool	Form::getIsSigned() const {

	return (_isSigned);
}

void	Form::beSigned(const Bureaucrat& signer) {

	if (signer.getGrade() > _signGrade) {

		signer.signForm(_name, false, "his Bereaucrat grade is too low");
		throw Form::GradeTooLowException();
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
