/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:37:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 22:41:28 by bjacobs          ###   ########.fr       */
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

static void	fillBrain(Brain& brain) {

	std::string	ideaList[] = {"running", "walking", "sleeping", "eating", "biting", "barking", "growling"};

	for (int i = 0; i < 100; i++) {

		brain.ideas[i] = ideaList[randomizer(7)];
	}
}

Dog::Dog(void) : Animal("Dog"), _brain(new Brain) {

	std::cout << "A default dog has appeared" << std::endl;
	if (this->_brain)
		fillBrain(*this->_brain);
	else
		std::cout << "No memory for dog brain" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source.getType()), _brain(new Brain) {

	std::cout << "A copied dog has appeared" << std::endl;
	if (this->_brain)
		*this->_brain = *source._brain;
	else
		std::cout << "No memory for dog brain" << std::endl;
}

Dog::~Dog(void) {

	std::cout << "A dog has disappeared" << std::endl;
	if (this->_brain)
		delete this->_brain;
}

Dog&	Dog::operator=(const Dog& rightSide) {

	std::cout << "A dog copied another dog" << std::endl;
	if (this != &rightSide) {

		this->type = rightSide.getType();
		if (this->_brain && rightSide._brain)
			*this->_brain = *rightSide._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const {

	std::string	dogNoises[] = {"woof-woof", "blaf-blaf", "voff-voff", 
							"guk-guk", "wan-wan", "meong-meong",
							"ham-ham", "gav-gav", "hav-hav"};

	std::cout << dogNoises[randomizer(9)] << std::endl;
}
