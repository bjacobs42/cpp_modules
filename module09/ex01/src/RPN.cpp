/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:37:45 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/06 23:15:44 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdint>
#include <cstring>
#include <limits>

RPN::RPN(void)
{}

RPN::RPN(const RPN& source)
{
	*this = source;
}

RPN::~RPN(void)
{}

RPN&	RPN::operator=(const RPN& rightSide)
{
	if (this != &rightSide)
		_stack = rightSide._stack;
	return (*this);
}

size_t	RPN::addNumber(const std::string& number)
{
	uint8_t	dots = 0;
	size_t	i;

	for (i = 0;  number[i]; ++i) {
		if (std::isdigit(number[i]))
			continue;
		if (number[i] != '.')
			break;
		++dots;
		if (dots > 1 || !number[i+1])
			return (false);
	}
	_stack.push(std::stod(number));
	return (i);
}

static double	returnPop(std::stack<double>& cont)
{
	double	ret = cont.top();
	cont.pop();
	return (ret);
}

void	RPN::executeOperation(const char& op)
{
	if (_stack.size() < 2)
		throw std::exception();
	switch (op) {
		case '+':
			_stack.top() += returnPop(_stack);
			break;
		case '-':
			_stack.top() -= returnPop(_stack);
			break;
		case '/':
			if (_stack.top() == 0) {
				_stack.pop();
				_stack.top() = std::numeric_limits<double>::infinity();
			}
			else
				_stack.top() /= returnPop(_stack);
			break;
		case '*':
			_stack.top() *= returnPop(_stack);
			break;
	}
}

void	RPN::processArguments(const std::string& arg)
{
	size_t	i;
	size_t	nread;

	i = 0;
	while (arg[i]) {
		if (std::isspace(arg[i])) {
			++i;
			continue;
		}
		if (std::isdigit(arg[i]) || arg[i] == '.') {
			nread = this->addNumber(&arg[i]);
			i += nread;
			continue;
		}
		if (std::strchr("+-/*", arg[i])) {
			this->executeOperation(arg[i]);
			++i;
			continue;
		}
		throw std::exception();
	}
}

double	RPN::getResult(void) const
{
	if (_stack.size() != 1)
		throw std::exception();
	return (_stack.top());
}
