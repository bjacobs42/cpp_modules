/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:17:13 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/11 20:25:46 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("RoughDiamond_clap_trap"), _name("RoughDiamond") {

	std::cout << "DiamondTrap default constructer called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_trap"), _name(name) {

	std::cout << "DiamondTrap string constructer called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source) : ClapTrap(source), \
													  ScavTrap(source), \
													  FragTrap(source) {

	std::cout << "DiamondTrap copy constructer called" << std::endl;
	*this = source;
}

DiamondTrap::~DiamondTrap(void) {

	std::cout << "DiamondTrap deconstucter called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rightSide) {

	std::cout << "DiamondTrap copy assignment called" << std::endl;
	if (this != &rightSide) {

		this->_name = rightSide.getName();
		this->_attackDamage = rightSide._attackDamage;
		this->_healthPoints = rightSide._healthPoints;
		this->_energyPoints = rightSide._energyPoints;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void) {

	std::cout << "I am " << this->_name << " and at the same time, I am " << ClapTrap::_name << std::endl;
}
