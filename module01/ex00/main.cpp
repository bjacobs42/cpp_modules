/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:01:17 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/11 17:34:32 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	ezra = Zombie("Ezra");
	Zombie*	wendigo = ezra.newZombie("Wendigo");

	ezra.announce();
	wendigo->announce();
	ezra.randomChump("Aithel");

	delete wendigo;
	return (0);
}

