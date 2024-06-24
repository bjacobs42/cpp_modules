/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:11:42 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/29 03:18:02 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include <iostream>

Character::Character(void) : _name("Aithel") {

	for (int i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " entered the chat" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {

	for (int i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " entered the chat" << std::endl;
}

Character::Character(const Character& source) : _name(source._name) {

	int	i;

	i = 0;
	while (source._inventory[i] && i < MAX_INVENTORY) {

		this->_inventory[i] = source._inventory[i]->clone();
		if (this->_inventory[i] == NULL) {

			std::cout << "Clone error, incomplete" << this->_name << " copy" << std::endl;
			break;
		}
		i++;
	}
	while (i < MAX_INVENTORY) {

		this->_inventory[i] = NULL;
		i++;
	}
	std::cout << this->_name << " clone entered the chat" << std::endl;
}

static bool	isUnique(AMateria* materia, AMateria** inventory, int start) {

	if (!materia)
		return (false);
	while (start < MAX_INVENTORY) {

		if (materia == inventory[start])
			return (false);
		start++;
	}
	return (true);
}

Character::~Character(void) {

	for (int i = 0; i < MAX_INVENTORY; i++) {

		if (isUnique(this->_inventory[i], this->_inventory, i + 1))
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	std::cout << this->_name << " has left the chat" << std::endl;
}

Character&	Character::operator=(const Character& rightSide) {

	int	i;

	if (this == &rightSide)
		return (*this);
	i = 0;
	while (rightSide._inventory[i] && i < MAX_INVENTORY) {

		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = rightSide._inventory[i]->clone();
		if (this->_inventory[i] == NULL) {

			std::cout << "Clone error, incomplete" << this->_name << " copy assignment" << std::endl;
			break;
		}
		i++;
	}
	while (i < MAX_INVENTORY) {

		this->_inventory[i] = NULL;
		i++;
	}
	std::cout << this->_name << " copied " << rightSide.getName() << std::endl;
	this->_name = rightSide.getName();
	return (*this);
}

const std::string&	Character::getName(void) const {

	return (this->_name);
}

void	Character::equip(AMateria* materia) {

	int	i;

	if (!materia) {

		std::cout << this->_name << " tried to equip a non existant materia" << std::endl;
		return;
	}
	i = 0;
	while (this->_inventory[i] && i < MAX_INVENTORY)
		i++;
	if (i >= MAX_INVENTORY) {

		std::cout << this->_name << "'s inventory is full" << std::endl;
		return;
	}
	this->_inventory[i] = materia;
	std::cout << this->_name << " equipped " << materia->getType() << " materia at " << i << std::endl;
}

void	Character::unequip(int index) {

	if (index < 0 || index > MAX_INVENTORY || !this->_inventory[index]) {

		std::cout << this->_name << " found nothing to unequip at " << index << std::endl;
		return;
	}
	std::cout << this->_name << " unequipped " << this->_inventory[index]->getType()
		<< " materia at " << index << std::endl;
	this->_inventory[index] = NULL;
}

void	Character::use(int index, ICharacter& target) {

	if (index < 0 || index > MAX_INVENTORY || !this->_inventory[index]) {

		std::cout << this->_name << " found nothing to use at " << index << std::endl;
		return;
	}
	this->_inventory[index]->use(target);
}
