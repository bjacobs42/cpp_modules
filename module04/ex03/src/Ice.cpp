/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:29:39 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:20:45 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& source) : AMateria(source.getType()) {}

Ice::~Ice(void) {}

Ice&	Ice::operator=(const Ice& rightSide) {

	this->type = rightSide.getType();
	return (*this);
}

AMateria*	Ice::clone(void) const {

	return (new Ice());
}

void	Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
