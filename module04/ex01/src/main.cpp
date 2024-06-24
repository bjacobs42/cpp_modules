/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:07 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/08 20:31:32 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

#define MAX_ANIMALS 4
static void	fillArray(Animal**	animals) {

	int	i;

	i = 0;
	while (i < MAX_ANIMALS / 2)
		animals[i++] = new Dog();
	while (i < MAX_ANIMALS)
		animals[i++] = new Cat();
}

static void	animalNoises(Animal* animal) {

	std::cout << "The " << animal->getType() << " says ";
	animal->makeSound();
}

int	main(void) {

	const WrongAnimal*	wrongCat = new WrongCat();
	Animal*				animals[MAX_ANIMALS];

	fillArray(animals);
	std::cout << std::endl;
	for (int i = 0; i < MAX_ANIMALS; ++i) {

		animalNoises(animals[i]);
	}
	std::cout << "The " << wrongCat->getType() << " says ";
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	for (int i = 0; i < MAX_ANIMALS; i++)
		delete animals[i];
	return (EXIT_SUCCESS);
}
