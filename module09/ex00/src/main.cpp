/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:06:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/25 18:45:08 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "btc: usage: [inputfile]" << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange	btc;
	if (!btc)
		return (EXIT_FAILURE);
	for (size_t i = 1; av[i]; ++i)
		btc.readInput(av[i]);
	return (EXIT_SUCCESS);
}
