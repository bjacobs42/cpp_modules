/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:06:41 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/22 01:00:10 by bjacobs          ###   ########.fr       */
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
	btc.readInput(av[1]);
	return (EXIT_SUCCESS);
}
