/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:37:45 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/23 06:23:50 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>
#include <iostream>
#include <limits>

RPN::RPN(void) {}
RPN::RPN(const RPN& source) { *this = source; }
RPN::~RPN(void) {}

RPN&	RPN::operator=(const RPN& rightSide) {
	if (this != &rightSide)
		_stack = rightSide._stack;
	return (*this);
}

bool	RPN::addNumber(const std::string& number, std::size_t& i) {
	uint8_t	dots = 0;
	std::size_t start = i;

	while (number[i]) {
		if (number[i] == '.') {
			if (++dots > 1 || !number[i+1])
				return (false);
		}
		else if (!std::isdigit(number[i]))
			break;
		++i;
	}
	try {
		_stack.push(std::stod(&number[start]));
	}
	catch (std::out_of_range& e) {
		return (false);
	}
	return (true);
}

static double	returnPop(std::stack<double>& cont) {
	double	ret = cont.top();
	cont.pop();
	return (ret);
}

bool	RPN::executeOperation(const char& op) {
	if (_stack.size() < 2)
		return (false);
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
	return (true);
}

bool	RPN::processArguments(const std::string& arg) {
	std::size_t			i;

	i = 0;
	while (arg[i]) {
		if (!std::isspace(arg[i])) {
			if (std::isdigit(arg[i]) || arg[i] == '.') {
				if (!this->addNumber(arg, i)) {
					std::cout << "Error: invalid :c" << std::endl;
					return (false);
				}
				continue;
			}
			if (!std::strchr("+-/*", arg[i]) || !this->executeOperation(arg[i])) {
				std::cout << "Error: invalid :c" << std::endl;
				return (false);
			}
		}
		++i;
	}
	return (true);
}

double	RPN::getResult(void) const {
	if (_stack.size() != 1)
		throw std::exception();
	return (_stack.top());
}
