/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:40:50 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/06 03:40:24 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <iostream>

void	toUpper(char& c) {
	c = std::toupper(c);
}

template <typename T>
void	addTen(T& x) {
	x += static_cast<T>(10);
}

template <typename T>
void	printNum(T& x) {

	std::cout << x << " ";
}

int	main(void) {

	char		helloWorld[] = "Hello World";
	int			arr[] = {1, 5, 9, 10};
	double		dArr[] = {1.0, 42.1, 9, 10};

	std::cout << "before: " << helloWorld << std::endl;
	iter<char>(helloWorld, 11, &toUpper);
	std::cout << "after: " << helloWorld << std::endl;

	std::cout << "-------------------------" << std::endl
			  << "before: ";
	iter(arr, 4, printNum);
	std::cout << std::endl;
	iter(arr, 4, &addTen);
	std::cout << "after: ";
	iter(arr, 4, printNum);
	std::cout << std::endl;

	std::cout << "-------------------------" << std::endl
			  <<"before: ";
	iter(dArr, 4, printNum);
	std::cout << std::endl;
	iter<double>(dArr, 4, &addTen<double>);
	std::cout << "after: ";
	iter(dArr, 4, printNum);
	std::cout << std::endl;
	return (0);
}
