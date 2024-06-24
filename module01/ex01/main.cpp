/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:01:17 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/12 16:37:38 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	ezra = Zombie("Ezra");
	Zombie	*horde = ezra.zombieHorde(5, "Aithel");

	ezra.announce();
	for (int i = 0; i < 5; i++)
		horde->announce();
	delete [] horde;
	return (0);
}
