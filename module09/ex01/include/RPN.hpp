/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:28:51 by bjacobs           #+#    #+#             */
/*   Updated: 2024/06/27 20:31:22 by bjacobs          ###   ########.fr       */
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

		size_t		addNumber(const std::string& number);
		void		executeOperation(const char& op);
		void		processArguments(const std::string& args);

		double		getResult(void) const;
};
