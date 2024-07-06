/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:22:24 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/06 22:21:22 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <vector>

class Span
{
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

		class SpanException : public  std::exception
		{
			private:
				std::string	_errorMsg;

			public:
				SpanException(const std::string &msg) : _errorMsg(msg)
				{}

				const char	*what(void) const noexcept override
				{
					return (_errorMsg.c_str());
				}
		};
};

#endif // !SPAN_HPP
