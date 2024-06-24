/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:37:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 22:41:38 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

static void	fillBrain(Brain& brain) {

	std::string	ideaList[] = {"running", "walking", "sleeping", "eating", "hitting", "purring", "meowing"};

	for (int i = 0; i < 100; i++) {

		brain.ideas[i] = ideaList[randomizer(7)];
	}
}

Cat::Cat(void) : Animal("Cat"), _brain(new Brain) {

	std::cout << "A default cat has appeared" << std::endl;
	if (this->_brain)
		fillBrain(*this->_brain);
	else
		std::cout << "No memory for cat brain" << std::endl;
}

Cat::Cat(const Cat& source) : Animal(source.getType()), _brain(new Brain) {

	std::cout << "A copied cat has appeared" << std::endl;
	if (this->_brain)
		*this->_brain = *source._brain;
	else
		std::cout << "No memory for cat brain" << std::endl;
}

Cat::~Cat(void) {

	std::cout << "A cat has disappeared" << std::endl;
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat& rightSide) {

	std::cout << "A cat copied another cat" << std::endl;
	if (this != &rightSide) {

		this->type = rightSide.getType();
		if (this->_brain && rightSide._brain)
			*this->_brain = *rightSide._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const {

	std::string	catNoises[] = {"meow", "miaou", "miau", "miao", "yaong", "myau", "mjau", "meo"};

	std::cout << catNoises[randomizer(8)] << std::endl;
}
