/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:30:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/06 22:34:34 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <ctime>

Span::Span(void) : _maxSize(0)
{}
Span::Span(const unsigned int& size) : _maxSize(size)
{}

Span::Span(const Span& source) : _maxSize(source._maxSize)
{
	*this = source;
}

Span::~Span(void)
{}

Span&	Span::operator=(const Span& rightSide)
{
	if (this != &rightSide)
	{
		if (_maxSize < rightSide._maxSize)
			throw Span::SpanException("Span copy assignment; rightside size too big");
		_numbers = rightSide._numbers;
	}
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
		throw Span::SpanException("fill; amount is larger than max size");
	std::srand(time(NULL));
	while (_numbers.size() < amount)
		_numbers.push_back(rand());
}
void	Span::fill(const unsigned int amount, const int number)
{
	if (amount + _numbers.size() > _maxSize)
		throw Span::SpanException("fill; amount is larger than max size");
	for (size_t i = 0; i < amount; ++i)
		_numbers.push_back(number);
}

void	Span::addNumber(const int& number) 
{
	if (_numbers.size() >= _maxSize)
		throw Span::SpanException("addNumber; max size reached");
	_numbers.push_back(number);
}

int	Span::shortestSpan(void)
{
	std::vector<int>	sortedNumbers;
	int					span, minSpan;

	if (_numbers.size() < 2)
		throw Span::SpanException("shortestSpan; insufficient elements");
	sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < _numbers.size(); ++i)
	{
		span = std::abs(sortedNumbers[i] - sortedNumbers[i-1]);
		if (span == 0)
			return (0);
		minSpan = std::min(span, minSpan);
	}
	return (minSpan);
}

int	Span::longestSpan(void)
{
	int	min, max;

	if (_numbers.size() < 2)
		throw Span::SpanException("longestSpan; insufficient elements");
	min = *std::min_element(_numbers.begin(), _numbers.end());
	max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
