/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:18:46 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/21 21:35:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>

int	main(void) {

	ClapTrap	larry;
	ClapTrap	aithel("Aithel");
	ClapTrap	larry2;

	larry2 = larry;
	aithel.attack(larry2.getName());
	larry2.takeDamage(aithel.getAttackDamage());
	larry.attack(aithel.getName());
	aithel.takeDamage(larry.getAttackDamage());
	aithel.attack(larry.getName());
	larry.takeDamage(100);
	larry.beRepaied(100);
	aithel.beRepaied(100);
	aithel.attack(larry.getName());
	larry.takeDamage(aithel.getAttackDamage());
	return (EXIT_SUCCESS);
}

