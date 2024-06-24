/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:37:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/12 00:44:26 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"
#include <iostream>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {

	std::cout << "A default wrong cat has appeared" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source.getType()) {

	std::cout << "A copied wrong cat has appeared" << std::endl;
	*this = source;
}

WrongCat::~WrongCat(void) {

	std::cout << "A wrong cat has disappeared" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rightSide) {

	std::cout << "A wrong cat copied another wrong cat" << std::endl;
	if (this != &rightSide) {

		this->type = rightSide.getType();
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {

	std::string	catNoises[] = {"meow", "miaou", "miau", "miao", "yaong", "myau", "mjau", "meo"};

	std::cout << catNoises[randomizer(8)] << std::endl;
}
