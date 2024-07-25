/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:45:17 by bjacobs           #+#    #+#             */
/*   Updated: 2024/07/25 21:50:50 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

/****************************** [ Uility Functions ] ******************************/

static char	getSeparator(const std::string& buff)
{
	char	separator;
	size_t	i;

	i = buff.find("date");
	if (i == std::string::npos)
		return (-1);
	i += 4;
	while (std::isspace(buff[i]))
		++i;
	if (!buff[i])
		return (-1);
	separator = buff[i];
	if (std::isspace(*(buff.end()-1)) || *(buff.end()-1) == separator)
		return (-1);
	return (separator);
}

static bool	separateFormat(const std::string& buff, std::string& date,
		float& value, const char separator, const unsigned int& lineIndex)
{
	size_t	separatorPos;
	int		i;

	separatorPos = buff.find(separator);
	if (separatorPos == std::string::npos)
	{
		std::cout << "Error: invalid format at line " << lineIndex << std::endl;
		return (false);
	}
	i = 0;
	while (std::isspace(date[i]))
		++i;
	date = buff.substr(i, separatorPos);
	while (std::isspace(date.back()))
		date.pop_back();
	try 
	{
		value = std::stof(buff.substr(separatorPos+1));
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error: not a number at line " << lineIndex << std::endl;
		return (false);
	}
	return (true);
}

static bool	isDashOrDigit(const unsigned char c)
{
	return (std::isdigit(c) || c == '-');
}

static bool	validDate(const std::string& string)
{
	std::string::const_iterator	it;
	size_t						dashCount;

	if (string.size() > 10)
		return (false);
	it = std::find_if_not(string.begin(), string.end(), isDashOrDigit);
	if (it != string.end())
		return (false);
	dashCount = std::count(string.begin(), string.end(), '-');
	if (dashCount != 2)
		return (false);
	return (true);
}

static bool	checkDate(std::string& date, const unsigned int& lineIndex)
{
	int						year, month, day;
	int						maxDay;
	std::size_t				dashPos;

	if (!validDate(date))
	{
		std::cout << "Error: invalid date(" << date << ") at line " << lineIndex << std::endl;
		return (false);
	}
	dashPos = date.find('-');
	month = std::stoi(&date[dashPos+1]);
	if (month < 1 || month > 12)
	{
		std::cout << "Error: invalid month(" << date << ") at line " << lineIndex << std::endl;
		return (false);
	}
	if (month == 2)
	{
		year = std::stoi(date);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			maxDay = 29;
		else
			maxDay = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;
	dashPos = date.find('-', dashPos+1);
	day = std::stoi(&date[dashPos+1]);
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

/****************************** [ Member Functoins ] ******************************/

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
		{
			insertData(_dataBase, date, value, lineIndex);
		}
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

bool				BitcoinExchange::operator!(void) const
{
	return (_dataBase.empty());
}

void	BitcoinExchange::readInput(const std::string& inputFile) const
{
	std::map<std::string, float>::const_iterator	it;
	std::ifstream									input(inputFile);
	std::string										buff, date;
	float											value;
	char											separator;

	if (_dataBase.empty())
		return;
	std::cout << inputFile << ";" << std::endl;
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
