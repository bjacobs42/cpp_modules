/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:08:04 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/18 00:00:51 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/MateriaSource.hpp"

int	main(void) {

	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character();

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	ezra = new Character("Ezra");

	me->use(0, *ezra);
	me->use(1, *ezra);
	me->unequip(1);
	me->use(1, *ezra);
	ezra->equip(tmp);
	ezra->use(0, *me);

	delete ezra;
	delete me;
	delete src;

	return (EXIT_SUCCESS);
}
