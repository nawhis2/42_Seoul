/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:19:59 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/08 19:16:03 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

int	Account::_nbAccounts 		 = 0;
int	Account::_totalAmount 	  	 = 0;
int	Account::_totalNbDeposits 	 = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	curr;
	std::tm*	timeinfo;
	char		buffer[16];
	
	std::time(&curr);
	timeinfo = std::localtime(&curr);
	std::strftime(buffer, 15, "%Y%m%d_%H%M%S", timeinfo);
	buffer[15] = '\0';
	std::cout << buffer ;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void 	Account::displayAccountsInfos(void)
{
	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void 	Account::displayStatus(void) const
{
	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit
			<< ";amount:" << deposit + _amount
			<< ";nb_deposits:" << ++_nbDeposits
			<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << '[';
	_displayTimestamp();
	std::cout << "] ";
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount ;
	if (_amount > withdrawal)
	{
		std::cout << ";withdrawal:" << withdrawal 
				<< ";amount:" << _amount - withdrawal
				<< ";nb_withdrawals:" << ++_nbWithdrawals
				<< std::endl ;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}		
}
