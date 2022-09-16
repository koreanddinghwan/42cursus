/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:27:12 by myukang           #+#    #+#             */
/*   Updated: 2022/07/16 03:33:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";"<<"total:"<<getTotalAmount()<<";"<<"deposits:"<<getNbDeposits()<<";"<<"withdrawals:"<<getNbWithdrawals()<<std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(0), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout<<"index:"<<_nbAccounts<<";"<<"amount:"<<checkAmount()<<";"<<"created"<<std::endl;
	_accountIndex = _nbAccounts++;
	_totalAmount += checkAmount();
}

Account::~Account()
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"<<"amount:"<<checkAmount()<<";"<<"closed"<<std::endl;
	_nbAccounts--;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"<<"p_amount:"<<checkAmount()<<";"<<"deposit:"<<deposit<<";"<<"amount:"<<checkAmount() + deposit<<";"<<"nb_deposits:"<<_nbDeposits<<std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	bool status;

	_displayTimestamp();
	if (_amount < withdrawal)
	{
		status = false;
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<checkAmount()<<";withdrawal:refused"<<std::endl;
	}
	else
	{
		status = true;
		_nbWithdrawals++;
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<checkAmount()<<";withdrawal:"<<withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout<<";amount:"<<checkAmount()<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;	
	}
	return (status);
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<checkAmount()<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout<<"[19920104_091532] ";
}

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{}
