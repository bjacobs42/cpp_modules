/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:45:17 by bjacobs           #+#    #+#             */
/*   Updated: 2024/03/28 00:26:13 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

/****************************** [ Uility Functons ] ******************************/

static char	getSeparator(const std::string& buff)
{
	char	separator;

	std::size_t	i;
	i = buff.find("date");
	if (i == std::string::npos)
		return (-1);
	i += 4;
	while (std::isspace(buff[i]))
		++i;
	if (!buff[i])
		return (-1);
	separator = buff[i++];
	while (std::isspace(buff[i]))
		++i;
	if (!buff[i])
		return (-1);
	return (separator);
}

static bool	separateFormat(const std::string& buff, std::string& date,
		float& value, const char separator, const unsigned int& lineIndex)
{
	std::size_t	found = buff.find(separator);

	if (found == std::string::npos)
	{
		std::cout << "Error: invalid format at line " << lineIndex << std::endl;
		return (false);
	}
	int	i = 0;
	while (std::isspace(date[i]))
		++i;
	date = buff.substr(i, found);
	while (std::isspace(date.back()))
		date.pop_back();
	try 
	{
		value = std::stof(buff.substr(found+1));
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error: not a number; line " << lineIndex << std::endl;
		return (false);
	}
	return (true);
}

static bool	validDate(const std::string& string)
{
	uint8_t	dashCount = 0;

	for (std::size_t i = 0; string[i]; ++i)
	{
		if (string[i] == '-')
		{
			if (++dashCount > 2)
				return (false);
		}
		else if (!std::isdigit(string[i]))
			return (false);
	}
	if (dashCount < 2)
		return (false);
	return (true);
}

static bool	checkDate(std::string& date, const unsigned int& lineIndex)
{
	int						year, month, day;
	int						maxDay;
	std::size_t				found;

	if (!validDate(date))
	{
		std::cout << "Error: invalid date(" << date << ") at line " << lineIndex << std::endl;
		return (false);
	}
	year = std::stoi(date);
	found = date.find('-');
	month = std::stoi(&date[found+1]);
	if (month < 1 || month > 12)
	{
		std::cout << "Error: invalid month(" << date << ") at line " << lineIndex << std::endl;
		return (false);
	}
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			maxDay = 29;
		else
			maxDay = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;
	found = date.find('-', found+1);
	day = std::stoi(&date[found+1]);
	if (day < 1 || day > maxDay)
	{
		std::cout << "Error: invalid day(" << date << ") at line " << lineIndex << std::endl;
		return (false);
	}
	return (true);
}

static bool	checkValue(const float& val, const unsigned int& lineIndex)
{
	if (val > 1000)
	{
		std::cout << "Error: number(" << val << ") too large at line " << lineIndex << std::endl;
		return (false);
	}
	else if (val < 0)
	{
		std::cout << "Error: negative number(" << val << ") at line " << lineIndex << std::endl;
		return (false);
	}
	return (true);
}

static void	insertData(std::map<std::string, float>& dataBase,
		const std::string& date, const float& value, const unsigned int& lineIndex)
{
	if (dataBase.find(date) != dataBase.end())
	{	
		std::cout << "Error: date redefined at line " << lineIndex << std::endl;
		return;
	}
	dataBase[date] = value;
}

/****************************** [ Member Functons ] ******************************/

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream	dataBase("src/data.csv");
	std::string		buff, date;
	float			value;
	char			separator;

	if (!dataBase)
	{
		std::cout << "Error: invalid data.csv" << std::endl;
		return;
	}
	std::getline(dataBase, buff);
	separator = getSeparator(buff);
	if (separator == -1)
	{
		std::cout << "Error: invalid format template in data.csv" << std::endl;
		return;
	}
	unsigned int	lineIndex = 2;
	while (std::getline(dataBase, buff))
	{
		if (separateFormat(buff, date, value, separator, lineIndex)
				&& checkDate(date, lineIndex))
			insertData(_dataBase, date, value, lineIndex);
		++lineIndex;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
	*this = source;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rightSide)
{
	if (this != &rightSide)
		_dataBase = rightSide._dataBase;
	return (*this);
}

void	BitcoinExchange::readInput(const std::string& inputFile)
{
	std::map<std::string, float>::iterator	it;
	std::ifstream							input(inputFile);
	std::string								buff, date;
	float									value;
	char									separator;

	if (_dataBase.empty())
		return;
	if (!input)
	{
		std::cout << "Error: invalid input file" << std::endl;
		return;
	}
	std::getline(input, buff);
	separator = getSeparator(buff);
	if (separator == -1)
	{
		std::cout << "Error: invalid format template" << std::endl;
		return;
	}
	std::cout << inputFile << ";" << std::endl;
	unsigned int	lineIndex = 2;
	while (std::getline(input, buff))
	{
		if (separateFormat(buff, date, value, separator, lineIndex)
				&& checkDate(date, lineIndex)
				&& checkValue(value, lineIndex))
		{
			it = _dataBase.lower_bound(date);
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
		++lineIndex;
	}
}
