/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:18:46 by bjacobs           #+#    #+#             */
/*   Updated: 2024/01/25 22:28:58 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>

int	main(void) {

	ClapTrap	larry;
	ClapTrap	aithel("Aithel");
	ScavTrap	merry;

	merry.guardGate();

	aithel.attack(larry.getName());
	larry.takeDamage(aithel.getAttackDamage());
	larry.attack(aithel.getName());
	aithel.takeDamage(larry.getAttackDamage());
	aithel.attack(larry.getName());
	larry.takeDamage(100);
	larry.beRepaied(100);
	aithel.beRepaied(100);
	aithel.attack(larry.getName());
	larry.takeDamage(aithel.getAttackDamage());

	merry.attack(aithel.getName());
	aithel.takeDamage(merry.getAttackDamage());
	merry.guardGate();
	aithel.attack(merry.getName());
	merry.takeDamage(aithel.getAttackDamage());
	return (EXIT_SUCCESS);
}

