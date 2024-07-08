/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:30:29 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/08 01:16:48 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>

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
	std::generate_n(std::back_inserter(_numbers), amount, std::rand);
}

void	Span::fill(const unsigned int amount)
{
	if (amount + _numbers.size() > _maxSize)
		throw Span::SpanException("fill; amount is larger than max size");
	std::srand(time(NULL));
	std::generate_n(std::back_inserter(_numbers), amount, std::rand);
}
void	Span::fill(const unsigned int amount, const int number)
{
	if (amount + _numbers.size() > _maxSize)
		throw Span::SpanException("fill; amount is larger than max size");
	std::fill_n(std::back_inserter(_numbers), amount, number);
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
	std::vector<int>	differences;
	int					minSpan;

	if (_numbers.size() < 2)
		throw Span::SpanException("shortestSpan; insufficient elements");
	sortedNumbers = _numbers;
	differences.resize(sortedNumbers.size());
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	std::adjacent_difference(sortedNumbers.begin(), sortedNumbers.end(), differences.begin());
	minSpan = *std::min_element(differences.begin() + 1, differences.end());
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
