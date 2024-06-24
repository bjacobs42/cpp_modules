/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:26:51 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 19:59:58 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& wep) : _name(name), _equipment(wep) {}

void	HumanA::attack(void) {

	std::cout << this->_name << " attacks with their " << this->_equipment.getType() << std::endl;
}
