#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void display(const char *str, int int_display, char delimeter)
{
    std::cout << str << int_display;
	if (delimeter)
		std::cout << delimeter;
}

Account::Account( int initial_deposit )
{
	// 
	_accountIndex = _nbAccounts;
	// при создании нового аккаунта, номер выбранного аккаунта растет
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(void)
{

}

Account::~Account(void)
{
	_displayTimestamp();
	// std::cout << ";closed" << std::endl;

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::cout << "[19920104_091532] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	display("accounts:", _nbAccounts, ';');
	display("total:", _totalAmount, ';');
	display("deposits:", _totalNbDeposits, ';');
	display("withdrawals:", _totalNbWithdrawals, ';');
	std::cout << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	display("index:", _accountIndex, ';');
	display("amount:", _amount, ';');
	display("deposits:", _nbDeposits, ';');
	display("withdrawals:", _nbWithdrawals, 0);
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	display("index:", _accountIndex, ';');
	display("p_amount:", _amount, ';');
	display("deposits:", deposit, ';');
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	display("amount:", _amount, ';');
	display("nb_deposits:", _nbDeposits, 0);
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	display("index:", _accountIndex, ';');
	display("p_amount:", _amount, ';');
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	display("withdrawal:", withdrawal, ';');
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -=withdrawal;
	display("amount:", _amount, ';');
	display("nb_withdrawals:", _nbWithdrawals, 0);
	std::cout << std::endl;
	return (true);
}
