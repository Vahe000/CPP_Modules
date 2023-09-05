/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:03:51 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/22 20:48:44 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}


// Account::Account( void ){}

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";" 
				<< "amount:" << _amount 
				<< ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
				<< "amount:" << _amount 
				<< ";closed" << std::endl;
}
void	Account::_displayTimestamp(void)
{
	time_t	tm;

	tm = time(NULL);
	struct	tm *p_local = localtime(&tm);
	std::cout << "[" << p_local->tm_year + 1900;
    std::cout << p_local->tm_mon + 1;
    std::cout << p_local->tm_mday;
    std::cout << "_";
    std::cout << p_local->tm_hour;
    std::cout << p_local->tm_min;
    std::cout << p_local->tm_sec << "] ";
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void)const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ":" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount  << ";";
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << ";" << std::endl;
	this->_totalAmount += deposit;
    this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "=" << std::endl;
		return (false);
	}
    std::cout << withdrawal << ";" ;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
	return (true);
}

