/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:17:44 by bjacobs           #+#    #+#             */
/*   Updated: 2023/07/10 16:34:20 by bjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ---------------[ De/Constructor ]--------------- */

Account::Account(int initialDesposit) : _amount (initialDesposit) {

	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_totalAmount += initialDesposit;
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "created" << std::endl;
}

Account::~Account(void) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "closed" << std::endl;
}

/* ---------------[ Accessor Functions ]--------------- */

int	Account::getNbAccounts(void) {

	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {

	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {

	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {

	return (Account::_totalNbWithdrawals);
}

/* ---------------[ Public Class Functions ]--------------- */

void	Account::makeDeposit(int deposit) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';'
			  << "deposit:" << deposit << ';';

	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ';'
			  << "nb_deposits:" << this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';';

	if (withdrawal > this->_amount) {

		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ';'
			  << "amount:" << this->_amount << ';'
			  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const {

	// THE HELL DOES THIS DO??
	return (this->_amount);
}

void	Account::displayStatus(void) const {

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "deposits:" << this->_nbDeposits << ';'
			  << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos(void) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
			  << "total:" << Account::getTotalAmount() << ';'
			  << "deposits:" << Account::getNbDeposits() << ';'
			  << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/* ---------------[ Private Class Functions ]--------------- */

void	Account::_displayTimestamp(void) {

	tm		*localTime;
	time_t	now;

	std::time(&now);
	localTime = localtime(&now);
	std::cout << '['
			  << localTime->tm_year + 1900
			  << std::setfill('0') << std::setw(2) << localTime->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << localTime->tm_mday
			  << '_'
			  << std::setfill('0') << std::setw(2) << localTime->tm_hour
			  << std::setfill('0') << std::setw(2) << localTime->tm_min
			  << std::setfill('0') << std::setw(2) << localTime->tm_sec
			  << "] ";
}
