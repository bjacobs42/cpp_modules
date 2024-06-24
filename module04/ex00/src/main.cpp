/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:04:07 by bjacobs           #+#    #+#             */
/*   Updated: 2024/02/08 20:08:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

int	main(void) {

	const WrongAnimal*	wrongCat = new WrongCat();
	const Animal*		meta = new Animal();
	const Animal*		dog = new Dog();
	const Animal*		cat = new Cat();

	std::cout << std::endl << "The " << dog->getType() << " says ";
	dog->makeSound();
	std::cout << "The " << cat->getType() << " says ";
	cat->makeSound();
	std::cout << "The " << wrongCat->getType() << " says ";
	wrongCat->makeSound();
	std::cout << "The " << meta->getType() << " says ";
	meta->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete wrongCat;
	delete meta;
	return (EXIT_SUCCESS);
}
