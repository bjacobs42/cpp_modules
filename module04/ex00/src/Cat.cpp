/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:37:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 22:37:31 by bjacobs          ###   ########.fr       */
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

Cat::Cat(void) : Animal("Cat") {

	std::cout << "A default cat has appeared" << std::endl;
}

Cat::Cat(const Cat& source) : Animal(source.getType()) {

	std::cout << "A copied cat has appeared" << std::endl;
}

Cat::~Cat(void) {

	std::cout << "A cat has disappeared" << std::endl;
}

Cat&	Cat::operator=(const Cat& rightSide) {

	std::cout << "A cat copied another cat" << std::endl;
	if (this != &rightSide) {

		this->type = rightSide.getType();
	}
	return (*this);
}

void	Cat::makeSound(void) const {

	std::string	catNoises[] = {"meow", "miaou", "miau", "miao", "yaong", "myau", "mjau", "meo"};

	std::cout << catNoises[randomizer(8)] << std::endl;
}
