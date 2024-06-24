/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:49:05 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/12 00:32:01 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("Unknown") {

	std::cout << "WrongAnimal default constructer called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {

	std::cout << "WrongAnimal string constructer called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) {

	std::cout << "WrongAnimal copy constructer called" << std::endl;
	*this = source;
}

WrongAnimal::~WrongAnimal(void) {

	std::cout << "WrongAnimal deconstructer called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rightSide) {

	std::cout << "WrongAnimal copy assignment called" << std::endl;
	this->type = rightSide.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const {

	return (this->type);
}

void	WrongAnimal::makeSound(void) const {

	std::cout << "*Unknown noises*" << std::endl;
}
