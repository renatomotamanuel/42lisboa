#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);

	std::cout << "[" << (lt->tm_year + 1900) << std::setw(2) << std::setfill('0') << lt->tm_mon + 1 << std::setw(2) 
	<< std::setfill('0') << lt->tm_mday << "_" << std::setw(2) << std::setfill('0') << lt->tm_hour << std::setw(2) 
	<< std::setfill('0') << lt->tm_min << std::setw(2) << std::setfill('0') << lt->tm_sec << "]";
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_totalAmount +=deposit;
	_amount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
		return std::cout << "refused" << std::endl, false;
	_totalAmount -=withdrawal;
	_amount -=withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbDeposits << std::endl;
	return true;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void ){
	return _nbAccounts;
}

int	Account::getTotalAmount( void ){
	return _totalAmount;
}

int	Account::getNbDeposits( void ){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const{
	return _amount;
}
