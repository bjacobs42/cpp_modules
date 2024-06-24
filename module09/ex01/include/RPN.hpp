/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:28:51 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/23 05:41:21 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>

class RPN {
	private:
		std::stack<double>	_stack;
	
	public:
		RPN(void);
		RPN(const RPN& source);
		~RPN(void);

		RPN&		operator=(const RPN& rightSide);

		bool		addNumber(const std::string& number, std::size_t& i);
		bool		executeOperation(const char& op);
		bool		processArguments(const std::string& args);

		double		getResult(void) const;
};
