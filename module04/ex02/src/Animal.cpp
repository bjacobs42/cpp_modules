/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:49:05 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/08 20:12:26 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Unknown") {

	//std::cout << "Animal default constructer called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {

	//std::cout << "Animal string constructer called" << std::endl;
}

Animal::Animal(const Animal& source) {

	//std::cout << "Animal copy constructer called" << std::endl;
	*this = source;
}

Animal::~Animal(void) {

	//std::cout << "Animal deconstructer called" << std::endl;
}

Animal&	Animal::operator=(const Animal& rightSide) {

	//std::cout << "Animal copy assignment called" << std::endl;
	this->type = rightSide.getType();
	return (*this);
}

std::string	Animal::getType(void) const {

	return (this->type);
}

void	Animal::makeSound(void) const {

	std::cout << "*Unknown noises*" << std::endl;
}
