/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:30:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/06/14 18:26:26 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

Span::Span(void) : _maxSize(0) {}
Span::Span(const unsigned int& size) : _maxSize(size) {}

Span::Span(const Span& source) : _maxSize(source._maxSize) {

	_numbers.resize(source._maxSize);
	*this = source;
}

Span::~Span(void) {}

Span&	Span::operator=(const Span& rightSide) {

	if (this == &rightSide)
		return (*this);
	if (_maxSize < rightSide._maxSize)
		throw std::exception();
	_numbers = rightSide._numbers;
	return (*this);
}

void	Span::fill(void) {

	std::srand(time(NULL));
	for (unsigned int amount =  _maxSize - _numbers.size(); amount; --amount)
		_numbers.push_back(rand());
}

void	Span::fill(const unsigned int amount) {

	if (amount + _numbers.size() > _maxSize)
		throw std::exception();
	std::srand(time(NULL));
	while (_numbers.size() < amount)
		_numbers.push_back(rand());
}
void	Span::fill(const unsigned int amount, const int number) {

	if (amount + _numbers.size() > _maxSize)
		throw std::exception();
	for (unsigned int i = 0; i < amount; ++i)
		_numbers.push_back(number);
}

void	Span::addNumber(const int& number) {

	if (_numbers.size() == _maxSize)
		throw std::exception();
	_numbers.push_back(number);
}

int	Span::shortestSpan(void) {

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite;
	int							shortestSpan;
	int							temp;

	if (_numbers.size() < 2)
		throw std::exception();
	ite = _numbers.end();
	it = _numbers.begin();
	shortestSpan = std::abs(*it++ - *it);
	while (it != ite) {

		temp = std::abs(*it - *(it+1));
		if (temp < shortestSpan)
			shortestSpan = temp;
		++it;
	}
	return (shortestSpan);
}

int	Span::longestSpan(void) {

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite;
	int							biggestSpan;
	int							temp;

	if (_numbers.size() < 2)
		throw std::exception();
	ite = _numbers.end();
	biggestSpan = 0;
	for (it = _numbers.begin(); it+1 != ite; ++it) {

		temp = std::abs(*it - *(it+1));
		if (temp > biggestSpan)
			biggestSpan = temp;
	}
	return (biggestSpan);
}
