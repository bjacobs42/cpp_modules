/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:53:22 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:56:40 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {

	for (int i = 0; i < MAX_MEMORY; i++) {

		this->_memory[i] = NULL;
	}
	std::cout << "A MateriaSource has appeared" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source) {

	for (int i = 0; i < MAX_MEMORY; i++) {

		this->_memory[i] = NULL;
	}
	*this = source;
	std::cout << "A MateriaSource has appeared" << std::endl;
}

MateriaSource::~MateriaSource(void) {

	for (int i = 0; this->_memory[i] && i < MAX_MEMORY; i++)
		delete this->_memory[i];
	std::cout << "A MateriaSource has disappeared" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rightSide) {

	int	i;

	if (this != &rightSide) {

		for (i = 0; rightSide._memory[i] && i < MAX_MEMORY; i++) {

			if (this->_memory[i])
				delete this->_memory[i];
			this->_memory[i] = rightSide._memory[i]->clone();
			if (!this->_memory[i]) {

				std::cout << "Materia Clone error, incomplete copy of MateriaSource" << std::endl;
				break;
			}
		}
		while (i < MAX_MEMORY) {
		
			if (this->_memory[i]) {

				delete this->_memory[i];
				this->_memory[i] = NULL;
			}
			
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* Materia) {

	int	i;

	for (i = 0; i < MAX_MEMORY; i++) {

		if (!this->_memory[i]) {

			this->_memory[i] = Materia;
			break;
		}
	}
	if (i == MAX_MEMORY)
		std::cout << "MateriaSource memory limit reached" << std::endl;
	else
		std::cout << Materia->getType() << " has been learned by a MateriaSource" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {

	for (int i = 0; this->_memory[i] && i < MAX_MEMORY; i++) {

		if (this->_memory[i]->getType() == type) {

			std::cout << "New " << type << " Materia created from MateriaSource" << std::endl;
			return (this->_memory[i]->clone());
		}
	}
	std::cout << "Materia not found in MateriaSource" << std::endl;
	return (NULL);
}
