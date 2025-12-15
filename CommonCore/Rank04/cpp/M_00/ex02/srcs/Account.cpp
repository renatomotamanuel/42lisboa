#include "Account.hpp"
#include <iostream>
#include <string>

void	Account::t::displayAccountsInfos( void ) {
	std::cout << getNbAccounts() ;//<< " " << _totalAmount << " " << _totalNbDeposits << " " << _totalNbWithdrawals;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit) {}

Account::~Account( void ) {
	std::cout << "Account has been deleted" << std::endl;
}


int	Account::t::getNbAccounts( void ){
	return ();
}
int	Account::getTotalAmount( void ) {}
int	Account::getNbDeposits( void ) {}
int	Account::getNbWithdrawals( void ) {}
void	Account::makeDeposit( int deposit ) {}
bool	Account::makeWithdrawal( int withdrawal ) {}
int		Account::checkAmount( void ) const {}
void	Account::displayStatus( void ) const {}