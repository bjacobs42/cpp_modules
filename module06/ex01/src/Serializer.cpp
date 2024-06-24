/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:20:15 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/05 01:26:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer& source) { *this = source; }
Serializer::~Serializer(void) {}

Serializer&	Serializer::operator=(const Serializer& rightSide) {

	if (this != &rightSide)
		return (*this);
	return (*this);
}

uintptr_t	Serializer::serialize(Data *pointer) {

	if (!pointer)
		return (0);
	return (reinterpret_cast<uintptr_t>(pointer));
}

Data*	Serializer::deserialize(uintptr_t raw) {

	if (!raw)
		return (0);
	return (reinterpret_cast<Data*>(raw));
}
