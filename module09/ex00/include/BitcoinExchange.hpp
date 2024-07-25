/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:40:42 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/25 18:40:35 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataBase;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& source);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& rightSide);
		bool				operator!(void) const;

		void				readInput(const std::string& inputFile) const;
};
