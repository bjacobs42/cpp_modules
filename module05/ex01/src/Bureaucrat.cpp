/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:18:21 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/04 00:12:26 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

static void	checkGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(void) : _name("Carl"), _grade(125) {

	//std::cout << "Bureaucrat Default constructer called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade) {

	//std::cout << "Bureaucrat Constructer called" << std::endl;
	checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& source) {

	//std::cout << "Bureaucrat Copy constructer called" << std::endl;
	*this = source;
	checkGrade(this->_grade);
}

Bureaucrat::~Bureaucrat(void) {

	//std::cout << "Bureaucrat Deconstructer called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rightSide) {

	//std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &rightSide) {

		this->_grade = rightSide.getGrade();
		checkGrade(this->_grade);
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& rightSide) {

	outStream << rightSide.getName() << "'s bureaucrat grade is " << rightSide.getGrade();
	return (outStream);
}

std::string	Bureaucrat::getName(void) const {

	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {

	return (this->_grade);
}

void	Bureaucrat::incrementGrade(const int& amount) {

	std::cout << "Incrementing " << _name << "'s bureaucrat grade by " << amount << std::endl;
	this->_grade -= amount;
	checkGrade(this->_grade);
}

void	Bureaucrat::deincrementGrade(const int& amount) {

	std::cout << "Deincrementing " << _name << "'s bureaucrat grade by " << amount << std::endl;
	this->_grade += amount;
	checkGrade(this->_grade);
}

void	Bureaucrat::signForm(const std::string formName, bool gotSigned, std::string reason) const {

	if (!gotSigned) {

		std::cout << _name << " couldn't sign the " << formName << " form as " << reason << std::endl;
	}
	else {
	
		std::cout << _name << " signed the " << formName << " form" << std::endl;
	}
}
