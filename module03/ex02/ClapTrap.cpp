/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:50:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/11 20:28:25 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

ClapTrap::ClapTrap(void) : \
	_name("Larry"), _healthPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap Default constructer called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : \
	_name(name), _healthPoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "ClapTrap string constructer called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & source) {

	std::cout << "ClapTrap copy constructer called" << std::endl;
	*this = source;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "ClapTrap deconstructer called" << std::endl;
}

std::string	ClapTrap::getName(void) const {

	return (this->_name);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {

	return (this->_energyPoints);
}

unsigned int	ClapTrap::getHealthPoints(void) const {

	return (this->_healthPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {

	return (this->_attackDamage);
}

ClapTrap &	ClapTrap::operator=(const ClapTrap & rightSide) {
 
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rightSide) {

		this->_name = rightSide.getName();
		this->_energyPoints = rightSide.getEnergyPoints();
		this->_healthPoints = rightSide.getHealthPoints();
		this->_attackDamage = rightSide.getAttackDamage();
	}
	return (*this);
}

void	ClapTrap::attack(const std::string & target) {

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
	std::cout << "ClapTrap #" << this->_name << attacks[randomizer(5)] << target << "'s " << areas[randomizer(7)]
			  << ", causing " << this->_attackDamage << " damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	std::string	deaths[] = {" got obliterated", " has died", " kicked the bucket", " turned to dust", \
							" got knocked out"};

	std::cout << this->_name << " took " << amount << " damage";
	if (this->_healthPoints == 0) {

		std::cout << ", even though " << this->_name << " is already dead" << std::endl;
		return;
	}
	else
		std::cout << std::endl;

	if (amount >= this->_healthPoints) {

		std::cout << this->_name << deaths[randomizer(5)] << std::endl;
		this->_healthPoints = 0;
	}
	else
		this->_healthPoints -= amount;
}

void	ClapTrap::beRepaied(unsigned int amount) {

	if (this->_energyPoints == 0 || this->_healthPoints == 0) {

		if (this->_energyPoints == 0)
			std::cout << this->_name << " tried to heal, but has no energy left" << std::endl;
		else
			std::cout << this->_name << " tried to heal, but " << this->_name << " is dead\?\?!!" << std::endl;;
		return;
	}
	std::cout << this->_name << " regained " << amount << " health" << std::endl;
	this->_energyPoints--;
	this->_healthPoints += amount;
}
