/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:13:06 by bjacobs           #+#    #+#             */
/*   Updated: 2024/01/25 20:00:50 by bjacobs          ###   ########.fr       */
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
			std::cout << "ScavTrap #" << this->_name << " tried to attack, but has no energy left" << std::endl;
		else
			std::cout << "ScavTrap #" << this->_name << " tried to attack, but " << this->_name << " is dead\?\?!!" << std::endl;;
		return;
	}
	this->_energyPoints--;
	if (this->gateKeeperMode)
		std::cout << "While in Gate Keeper Mode, ";
	std::cout << "ScavTrap #" << this->_name << attacks[randomizer(5)] << target << "'s " << areas[randomizer(7)]
			  << ", causing " << this->_attackDamage << " damage" << std::endl;
}

void	ScavTrap::guardGate(void) {

	if (this->_healthPoints == 0)
		std::cout << "ScavTrap #" << this->_name << " tried to Go in Keeper Mode, but is dead" << std::endl;
	else if (!this->gateKeeperMode) {

		std::cout << "ScavTrap #" << this->_name << " is in Gate Keeper Mode" << std::endl;
		this->gateKeeperMode = true;
	}
	else {

		std::cout << "ScavTrap #" << this->_name << " is no longer in Gate Keeper Mode" << std::endl;
		this->gateKeeperMode = false;
	}
}
