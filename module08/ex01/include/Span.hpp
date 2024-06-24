/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:22:24 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/10 23:50:59 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span {

	private:
		const unsigned int	_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		Span(const unsigned int& size);
		Span(const Span& source);
		~Span(void);

		Span&	operator=(const Span& rightSide);

		void	fill(void);
		void	fill(const unsigned int amount);
		void	fill(const unsigned int amount, const int number);
		void	addNumber(const int& number);
		int		shortestSpan(void);
		int		longestSpan(void);
};

#endif // !SPAN_HPP
