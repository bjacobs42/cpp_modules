/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:07 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/08 20:09:53 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

#define MAX_ANIMALS 2
static void	fillArray(Animal**	animals) {

	int	i;

	i = 0;
	while (i < MAX_ANIMALS / 2)
		animals[i++] = new Dog();
	while (i < MAX_ANIMALS)
		animals[i++] = new Cat();
}

int	main(void) {

	const WrongAnimal*	wrongCat = new WrongCat();
	//Animal				impossible;
	Animal*				animals[MAX_ANIMALS];

	fillArray(animals);
	std::cout << std::endl << "The " << animals[0]->getType() << " says ";
	animals[0]->makeSound();
	std::cout << "The " << animals[MAX_ANIMALS - 1]->getType() << " says ";
	animals[MAX_ANIMALS - 1]->makeSound();
	std::cout << "The " << wrongCat->getType() << " says ";
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongCat;
	for (int i = 0; i < MAX_ANIMALS; i++)
		delete animals[i];
	return (EXIT_SUCCESS);
}
