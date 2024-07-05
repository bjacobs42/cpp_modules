/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:30:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/05 20:36:19 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <vector>

Span::Span(void) : _maxSize(0)
{}
Span::Span(const unsigned int& size) : _maxSize(size)
{}

Span::Span(const Span& source) : _maxSize(source._maxSize)
{
	_numbers.resize(source._maxSize);
	*this = source;
}

Span::~Span(void)
{}

Span&	Span::operator=(const Span& rightSide)
{
	if (this == &rightSide)
		return (*this);
	if (_maxSize < rightSide._maxSize)
		throw std::exception();
	_numbers = rightSide._numbers;
	return (*this);
}

void	Span::fill(void)
{
	std::srand(time(NULL));
	size_t amount = _maxSize - _numbers.size();
	while (amount--)
		_numbers.push_back(rand());
}

void	Span::fill(const unsigned int amount)
{
	if (amount + _numbers.size() > _maxSize)
		throw std::exception();
	std::srand(time(NULL));
	while (_numbers.size() < amount)
		_numbers.push_back(rand());
}
void	Span::fill(const unsigned int amount, const int number)
{
	if (amount + _numbers.size() > _maxSize)
		throw std::exception();
	for (size_t i = 0; i < amount; ++i)
		_numbers.push_back(number);
}

void	Span::addNumber(const int& number) 
{
	if (_numbers.size() == _maxSize)
		throw std::exception();
	_numbers.push_back(number);
}

int	Span::shortestSpan(void)
{
	std::vector<int>	sortedNumbers;

	if (_numbers.size() < 2)
		throw std::exception();
	auto	toAbs = [](int &n)
	{
		n = std::abs(n);
	};
	sortedNumbers = _numbers;
	std::for_each(sortedNumbers.begin(), sortedNumbers.end(), toAbs);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return (sortedNumbers[1] - sortedNumbers[0]);
}

int	Span::longestSpan(void)
{
	std::vector<int>::iterator	minIt, maxIt;

	if (_numbers.size() < 2)
		throw std::exception();
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return (*maxIt - *minIt);
}
