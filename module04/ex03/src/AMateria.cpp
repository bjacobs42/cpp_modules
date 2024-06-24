/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 01:01:37 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/17 23:51:37 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : type("unknown") {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& source) : type(source.getType()) {}

AMateria::~AMateria(void) {}

AMateria&	AMateria::operator=(const AMateria& rightSide) {

	if (this != &rightSide)
		this->type = rightSide.type;
	return (*this);
}

const std::string&	AMateria::getType(void) const {

	return (this->type);
}

void	AMateria::use(ICharacter& target) {

	std::cout << "* shoots an unknown magic at " << target.getName() << std::endl;
}
