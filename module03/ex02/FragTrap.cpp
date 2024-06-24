/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:13:06 by bjacobs           #+#    #+#             */
/*   Updated: 2024/01/25 22:20:16 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

static unsigned int	randomizer(unsigned int max) {

	static unsigned int	seed = time(0);

	srand(time(0));
	seed *= rand();
	return (seed % max);
}

FragTrap::FragTrap(void) : ClapTrap("Tim") {

	std::cout << "FragTrap default constructer called" << std::endl;
	this->_healthPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {

	std::cout << "FragTrap string constructer called" << std::endl;
	this->_healthPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source.getName()) {

	std::cout << "FragTrap copy constructer called" << std::endl;
	*this = source;
}

FragTrap::~FragTrap(void) {

	std::cout << "FragTrap Deconstructer called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rightSide) {

	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rightSide) {

		this->_name = rightSide.getName();
		this->_healthPoints = rightSide.getHealthPoints();
		this->_energyPoints = rightSide.getEnergyPoints();
		this->_attackDamage = rightSide.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {

	if (this->_healthPoints == 0)
		std::cout << "FragTrap #" << this->_name << " tried to do a high five, but is dead" << std::endl;
	else
		std::cout << "FragTrap #" << this->_name << " is holding up their hand for a high five" << std::endl;
}

void	FragTrap::attack(const std::string & target) {

	std::string	attacks[] = {" kicked ", " punched ", " bit ", " slapped ", " uppercutted "};
	std::string	areas[] = {"groin", "face", "chest", "legs", "stomach", "arms", "liver"};

	if (this->_energyPoints == 0 || this->_healthPoints == 0) {

		if (this->_energyPoints == 0)
			std::cout  << "FragTrap #" << this->_name << " tried to attack, but has no energy left" << std::endl;
		else
			std::cout << "FragTrap #" << this->_name << " tried to attack, but " << this->_name << " is dead\?\?!!" << std::endl;;
		return;
	}
	this->_energyPoints--;
	std::cout << "FragTrap #" << this->_name << attacks[randomizer(5)] << target << "'s " << areas[randomizer(7)]
			  << ", causing " << this->_attackDamage << " damage" << std::endl;
}
