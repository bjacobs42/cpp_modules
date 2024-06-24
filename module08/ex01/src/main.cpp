/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:46:01 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/11 00:12:46 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ostream>

int	main(void) {

	Span	sp(5);
	Span	sp2(10000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Subject test:" << std::endl
			  << sp.shortestSpan() << std::endl
			  << sp.longestSpan() << std::endl << std::endl;
	sp2.fill();
	//sp2.addNumber(6);
	//sp2.addNumber(3);
	std::cout << "10.000 numbers test:" << std::endl
			  << sp2.shortestSpan() << std::endl
			  << sp2.longestSpan() << std::endl;
	return (0);
}
