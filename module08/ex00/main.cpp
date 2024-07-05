/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:56:09 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/05 18:59:39 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <string>
#include <vector>
#include <iostream>

template <typename Container, typename T>
void	printContainer(Container& cont)
{
	bool	first;

	if (cont.empty())
	{
		std::cout << "{ }";
		return;
	}
	std::cout << "{ ";
	first = true;
	for (const T val: cont)
	{
		if (!first)
			std::cout << ", ";
		std::cout << val;
		first = false;
	}
	std::cout << " }";
};

template <typename Container, typename T>
void	useEasyFind(Container& cont, const T& target)
{
	std::cout << "searching " << target << " in container ";
	printContainer<Container, T>(cont);
	std::cout << std::endl;
	if (easyFind<Container>(cont, static_cast<int>(target)) != cont.end())
	{
		std::cout << target << " was found in container ";
		printContainer<Container, T>(cont);
	}
	else
	{
		std::cout << target << " was not found in container ";
		printContainer<Container, T>(cont);
	}
	std::cout << std::endl << std::endl;
}

int	main(void) {

	std::vector<int>	v2 = {10, 5};
	std::vector<double>	v2d = {42.0, 5.0};
	std::string			s("Hello World");
	std::string			sEmpty;

	useEasyFind<std::vector<int>, int>(v2, 5);
	useEasyFind<std::vector<int>, int>(v2, 9);
	useEasyFind<std::vector<double>, double>(v2d, 5);
	useEasyFind<std::string, char>(s, 'W');
	useEasyFind<std::string, char>(sEmpty, 'W');
	return (0);
}
