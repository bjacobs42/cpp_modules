/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:29:19 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/11 07:34:54 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

	private:

	public:
		MutantStack(void) {};
		MutantStack(const MutantStack& source) { *this = source; };
		~MutantStack(void) {};

		MutantStack&	operator=(const MutantStack& rightSide) {

			std::stack<T, Container>::operator=(rightSide);
			return (*this);
		};

		typedef typename Container::iterator iterator;

		iterator	begin(void) { return (this->c.begin()); };
		iterator	end(void) { return(this->c.end()); };
};
