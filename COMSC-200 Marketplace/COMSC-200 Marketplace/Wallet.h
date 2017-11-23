#ifndef WALLET
#define WALLET

class Wallet
{
public:
	class invalidTransferAmount //Change from return bool to exception handling.
	{

	};
	Wallet();
	bool addFunds(const double&);
	bool removeFunds(const double&);
	bool operator+=(const double&);
	bool operator-=(const double&);
private:
	double funds;
};

#endif // !WALLET

