/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:18:46 by bjacobs           #+#    #+#             */
/*   Updated: 2024/01/25 22:37:56 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>

int	main(void) {

	ClapTrap	larry;
	ClapTrap	aithel("Aithel");
	ScavTrap	ezra("Ezra");
	DiamondTrap	toff("Toff");

	aithel.attack(ezra.getName());
	ezra.takeDamage(aithel.getAttackDamage());
	larry.attack(aithel.getName());
	aithel.takeDamage(larry.getAttackDamage());
	aithel.attack(larry.getName());
	larry.takeDamage(100);
	larry.beRepaied(100);
	aithel.beRepaied(40);
	aithel.attack(larry.getName());
	larry.takeDamage(aithel.getAttackDamage());
	ezra.attack(aithel.getName());
	aithel.takeDamage(ezra.getAttackDamage());
	ezra.guardGate();
	toff.whoAmI();
	toff.guardGate();
	toff.highFivesGuys();
	toff.attack("Aithel");
	aithel.takeDamage(toff.getAttackDamage());
	return (EXIT_SUCCESS);
}

