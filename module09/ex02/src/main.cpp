/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 23:26:14 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/26 15:53:24 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <chrono>

#define MAX_NUM_PRINTS 10

template <typename Cont>
static void	printCont(Cont& container)
{
	if (container.empty()) return;

	size_t					i;
	typename Cont::iterator	it;
	typename Cont::iterator	ite;

	i = 0;
	it = container.begin();
	ite = container.end();
	while (it != ite && i < (size_t)MAX_NUM_PRINTS)
	{
		if (i)
			std::cout << ", ";
		std::cout << *it;
		++it;
		++i;
	}
	if (it != ite)
		std::cout << ", [...]";
	std::cout << std::endl;
}

static bool	onlyPositiveNumbers(char** args)
{
	for (std::size_t i = 0; args[i]; ++i)
	{
		for (std::size_t j = 0; args[i][j]; ++j)
		{
			if (std::isspace(args[i][j]))
				continue;
			if (!std::isdigit(args[i][j]))
				return (false);
		}
	}
	return (true);
}

int	main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "PmergeMe: Usage: [positive numbers]" << std::endl;
		return (EXIT_SUCCESS);
	}
	if (!onlyPositiveNumbers(&av[1]))
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<unsigned int>	v;
	std::list<unsigned int>		l;

	std::chrono::time_point<std::chrono::system_clock>	start =
		std::chrono::high_resolution_clock::now();
	if (!PmergeMe::initCont<std::vector<unsigned int>>(&av[1], v))
		return (EXIT_FAILURE);
	std::chrono::time_point<std::chrono::system_clock>	end =
		std::chrono::high_resolution_clock::now();

	float	vTime = std::chrono::duration<float>(end - start).count() * 1000.0f;
	float	lTime;
	std::cout << "before: ";
	printCont(v);

	start = std::chrono::high_resolution_clock::now();
	PmergeMe::mergeSort(v);
	end = std::chrono::high_resolution_clock::now();
	vTime += std::chrono::duration<float>(end - start).count() * 1000.0f;

	start = std::chrono::high_resolution_clock::now();
	if (!PmergeMe::initCont<std::list<unsigned int>>(&av[1], l))
		return (EXIT_FAILURE);
	PmergeMe::mergeSort(l);
	end = std::chrono::high_resolution_clock::now();
	lTime = std::chrono::duration<float>(end - start).count() * 1000.0f;

	std::cout << "after: ";
	printCont(l);

	std::cout << std::fixed << "Time to process a range of " << v.size() << " elements with std::vector : " << vTime << " ms" << std::endl
			  << "Time to process a range of " << l.size() << " elements with std::list : " << lTime << " ms" << std::endl;
	return (EXIT_SUCCESS);
}
