/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:09:31 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 20:03:42 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int	main(void) {

	Weapon	katana = Weapon("katana");
	Weapon	odachi = Weapon("odachi");

	HumanA	aithel = HumanA("Aithel", odachi);
	HumanB	laci = HumanB("Laci");

	laci.attack();
	std::cout << "Aithel dodges" << std::endl;
	aithel.attack();
	std::cout << "Laci dodges and grabs a katana" << std::endl;
	laci.setWeapon(katana);
	laci.attack();
	std::cout << "Aithel parries" << std::endl;
	aithel.attack();
	std::cout << "COUNTER!!!" << std::endl
			  << "Laci's " << katana.getType() << " bent" << std::endl
			  << "Aithel's " << odachi.getType() << "'s handle broke" << std::endl;
	katana.setType("bent katana");
	odachi.setType("hands");
	laci.attack();
	std::cout << "Laci missed" << std::endl;
	aithel.attack();
	std::cout << "CRITICAL!!!" << std::endl
			  << "Aithel wins!" << std::endl;
	return (EXIT_SUCCESS);
}
