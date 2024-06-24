/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:18:46 by bjacobs           #+#    #+#             */
/*   Updated: 2023/09/05 17:28:43 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>

int	main(void) {

	ClapTrap	larry;
	ClapTrap	aithel("Aithel");
	ScavTrap	ezra("Ezra");
	FragTrap	unknown;

	aithel.attack(ezra.getName());
	ezra.takeDamage(aithel.getAttackDamage());
	larry.attack(aithel.getName());
	aithel.takeDamage(larry.getAttackDamage());
	aithel.attack(larry.getName());
	larry.takeDamage(100);
	larry.beRepaied(100);
	aithel.beRepaied(100);
	aithel.attack(larry.getName());
	larry.takeDamage(aithel.getAttackDamage());
	ezra.guardGate();
	ezra.attack(aithel.getName());
	aithel.takeDamage(ezra.getAttackDamage());

	unknown.highFivesGuys();
	unknown.attack(ezra.getName());
	ezra.takeDamage(unknown.getAttackDamage());
	return (EXIT_SUCCESS);
}

