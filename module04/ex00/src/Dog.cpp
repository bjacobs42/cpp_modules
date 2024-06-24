/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:37:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/12 00:17:31 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

Dog::Dog(void) : Animal("Dog") {

	std::cout << "A default dog has appeared" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source.getType()) {

	std::cout << "A copied dog has appeared" << std::endl;
}

Dog::~Dog(void) {

	std::cout << "A dog has disappeared" << std::endl;
}

Dog&	Dog::operator=(const Dog& rightSide) {

	std::cout << "A dog copied another dog" << std::endl;
	if (this != &rightSide) {

		this->type = rightSide.getType();
	}
	return (*this);
}

void	Dog::makeSound(void) const {

	std::string	dogNoises[] = {"woof-woof", "blaf-blaf", "voff-voff", 
							"guk-guk", "wan-wan", "meong-meong",
							"ham-ham", "gav-gav", "hav-hav"};

	std::cout << dogNoises[randomizer(9)] << std::endl;
}
