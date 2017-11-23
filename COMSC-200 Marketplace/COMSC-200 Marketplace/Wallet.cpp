#include "Wallet.h"
Wallet::Wallet()
{
	funds = 0;
}

bool Wallet::addFunds(const double& desiredAddition)
{
	bool valid = (desiredAddition > 0.0);
	if (valid)
	{
		funds += desiredAddition;
	}
	return valid;
}


bool Wallet::removeFunds(const double& desiredRemoval)
{
	bool valid = (desiredRemoval > 0.0);
	if (valid)
	{
		funds -= desiredRemoval;
	}
	return valid;
}

bool Wallet::operator+=(const double& desiredAddition)
{
	return addFunds(desiredAddition);
}
bool Wallet::operator-=(const double& desiredAddition)
{
	return removeFunds(desiredAddition);
}