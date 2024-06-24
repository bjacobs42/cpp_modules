/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:13:19 by bjacobs           #+#    #+#             */
/*   Updated: 2023/08/13 22:48:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>

Brain::Brain(void) {

	std::cout << "Brain constructer called" << std::endl;
}

Brain::Brain(const Brain& source) {

	std::cout << "Brain copy constructer called" << std::endl;
	*this = source;
}

Brain::~Brain(void) {

	std::cout << "Brain deconstucter called" << std::endl;
}

Brain&	Brain::operator=(const Brain& rightSide) {

	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) {

		this->ideas[i] = rightSide.ideas[i];
	}
	return (*this);
}
