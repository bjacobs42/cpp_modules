/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:13:06 by bjacobs           #+#    #+#             */
/*   Updated: 2023/09/05 17:21:04 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

ScavTrap::ScavTrap(void) : ClapTrap("Colin") {

	std::cout << "ScavTrap default constructer called" << std::endl;
	this->_healthPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {

	std::cout << "ScavTrap string constructer called" << std::endl;
	this->_healthPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source.getName()) {

	std::cout << "ScavTrap copy constructer called" << std::endl;
	*this = source;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap Deconstructer called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rightSide) {

	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rightSide) {

		this->_name = rightSide.getName();
		this->_healthPoints = rightSide.getHealthPoints();
		this->_energyPoints = rightSide.getEnergyPoints();
		this->_attackDamage = rightSide.getAttackDamage();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string & target) {

	std::string	attacks[] = {" kicked ", " punched ", " bit ", " slapped ", " uppercutted "};
	std::string	areas[] = {"groin", "face", "chest", "legs", "stomach", "arms", "liver"};

	if (this->_energyPoints == 0 || this->_healthPoints == 0) {

		if (this->_energyPoints == 0)
			std::cout << this->_name << " tried to attack, but has no energy left" << std::endl;
		else
			std::cout << this->_name << " tried to attack, but " << this->_name << " is dead\?\?!!" << std::endl;;
		return;
	}
	this->_energyPoints--;
	if (this->gateKeeperMode)
		std::cout << "While guarding the gate, ";
	else
		std::cout << "while not guarding the gate, ";
	std::cout << "ScavTrap #" << this->_name << attacks[randomizer(5)] << target << "'s " << areas[randomizer(7)]
			  << ", causing " << this->_attackDamage << " damage" << std::endl;
}

void	ScavTrap::guardGate(void) {

	if (this->_healthPoints == 0) {

		std::cout << this->_name << " tried to guard the gate, but is dead" << std::endl;
		return;
	}
	if (!this->gateKeeperMode) {

		std::cout << this->getName() << " is guarding the gate" << std::endl;
		this->gateKeeperMode = true;
	}
	else {

		std::cout << this->getName() << " stopped guarding the gate" << std::endl;
		this->gateKeeperMode = false;
	}
}
