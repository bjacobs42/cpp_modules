/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:29:39 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:53:23 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& source) : AMateria(source.getType()) {}

Cure::~Cure(void) {}

Cure&	Cure::operator=(const Cure& rightSide) {

	this->type = rightSide.getType();
	return (*this);
}

AMateria*	Cure::clone(void) const {

	return (new Cure());
}

void	Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
