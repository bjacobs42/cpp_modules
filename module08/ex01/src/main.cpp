/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:46:01 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/08 01:17:19 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ostream>

int	main(void) {

	Span	sp(5);
	Span	sp2(10000);

	try
	{
		sp.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(20);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Subject test:" << std::endl
			  << sp.shortestSpan() << std::endl
			  << sp.longestSpan() << std::endl;

	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.fill();
	std::cout << "10.000 numbers test:" << std::endl
			  << sp2.shortestSpan() << std::endl
			  << sp2.longestSpan() << std::endl;
	return (0);
}
