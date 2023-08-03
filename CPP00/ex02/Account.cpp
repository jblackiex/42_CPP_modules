#include "Account.hpp"

#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::Account(void) {}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}


int	Account::getTotalAmount(void) {
	return _totalAmount;
}


int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << "deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void) {
	std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::localtime(&currentTime);

    std::cout << "[" 
              << localTime->tm_year + 1900
              << localTime->tm_mon + 1
              << localTime->tm_mday << '_'
              << localTime->tm_hour
              << localTime->tm_min
              << localTime->tm_sec << "] ";
}

void	Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	Account::_displayTimestamp();
	int cont = this->_amount;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << cont << ";"
	<< "deposit:" << deposit << ";" << "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";"
		<< "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	int cont = this->_amount;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << cont << ";"
	<< "withdrawal:" << withdrawal << ";" << "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
	<< "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}