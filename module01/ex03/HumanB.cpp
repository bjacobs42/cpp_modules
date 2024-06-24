/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:59:50 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 19:58:08 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _equipment(NULL) {}

void	HumanB::attack(void) {

	std::string	wep;

	if (this->_equipment)
		wep = _equipment->getType();
	else
		wep = "hands";
	std::cout << this->_name << " attacks with their " << wep << std::endl;
}

void	HumanB::setWeapon(Weapon& wep) {

	this->_equipment = &wep;
}
