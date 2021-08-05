#ifndef Accounts_H
#define Accounts_H
#include <iostream>
using namespace std;

class Account
{
	string accountNo;
	string accountName;
	float balance = 0;

public:
	Account(string str = "") : accountName(str) {}

	void setAccountName(string str)
	{
		accountName = str;
	}

	void setAccountNo(string prefix, string str)
	{
		accountNo = prefix + str;
	}

	void setBalance(float balance)
	{
		balance = balance;
	}

	string getAccountNmae()
	{
		return accountName;
	}

	string getAccountNo()
	{
		return accountNo;
	}
	float getBalance()
	{
		return balance;
	}

	void show()
	{
		cout << "Account No     : " << accountNo << "\n";
		cout << "Account Name   : " << accountName << "\n";
		cout << "Balance        : " << balance << "\n";
	}
};

class CurrentAccount : public Account
{
	const static int serviceCharge = 100;
	const static int accountPrefix = 100;
	static int nextAccount;
	int nextAccountNo()
	{
		return ++nextAccount;
	}

public:
	CurrentAccount()
	{
		setAccountNo(to_string(accountPrefix), to_string(nextAccountNo()));
	}

	~CurrentAccount()
	{
		nextAccount--;
	}

	void setNextAccount(int val)
	{
		nextAccount = val;
	}
	int getServiceCharge() const
	{
		return serviceCharge;
	}
	int getAccountPrefix() const
	{
		return accountPrefix;
	}
	int getNextAccount() const
	{
		return nextAccount;
	}

	void show()
	{
		cout << "Current Account: \n";
		Account::show();
		cout << "Service Charge : " << serviceCharge << "\n";
		cout << "Account Prefix : " << accountPrefix << "\n";
	}
};

class SavingsAccount : public Account
{
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 200;
	static int nextAccount;

	int nextAccountNo()
	{
		return ++nextAccount;
	}

public:
	SavingsAccount(float ir = 0, float mda = 0)
	{
		interestRate = ir;
		monthlyDepositAmount = mda;
		setAccountNo(to_string(accountPrefix), to_string(nextAccountNo()));
	}

	~SavingsAccount() { nextAccount--; }

	float getInterest() { return interestRate; }
	float getmonthlyDepositAmount() { return monthlyDepositAmount; }
	int getAccountPrefix() { return accountPrefix; }

	void setInterestRate(float ir) { interestRate = ir; }
	void setmonthlyDepositAmount(float mda) { monthlyDepositAmount = mda; }

	void show()
	{
		cout << "Savings Account\n";
		Account::show();
		cout << "Interest Rate          : " << interestRate << "\n";
		cout << "Monthly Deposit amount : " << monthlyDepositAmount << "\n";
		cout << "Account Prefix         : " << accountPrefix << "\n";
	}
};

class MonthlyDepositScheme : public Account
{
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 300;
	static int nextAccount;

	int nextAccountNo()
	{
		return ++nextAccount;
	}

public:
	MonthlyDepositScheme(float ir = 0, float mda = 0)
	{
		interestRate = ir;
		monthlyDepositAmount = mda;
		setAccountNo(to_string(accountPrefix), to_string(nextAccountNo()));
	}
	~MonthlyDepositScheme() { nextAccount--; }

	float getInterest() { return interestRate; }
	float getmonthlyDepositAmount() { return monthlyDepositAmount; }
	int getAccountPrefix() { return accountPrefix; }

	void setInterestRate(float ir) { interestRate = ir; }
	void setmonthlyDepositAmount(float mda) { monthlyDepositAmount = mda; }

	void show()
	{
		cout << "Monthly Deposit Scheme\n";
		Account::show();
		cout << "Interest Rate          : " << interestRate << "\n";
		cout << "Monthly Deposit amount : " << monthlyDepositAmount << "\n";
		cout << "Account Prefix         : " << accountPrefix << "\n";
	}
};

class LoanAccount : public Account
{
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 900;
	static int nextAccount;

	int nextAccountNo()
	{
		return ++nextAccount;
	}

public:
	LoanAccount(float ir = 0, float mda = 0)
	{
		interestRate = ir;
		monthlyDepositAmount = mda;
		setAccountNo(to_string(accountPrefix), to_string(nextAccountNo()));
	}

	~LoanAccount() { nextAccount--; }

	float getInterest() { return interestRate; }
	float getmonthlyDepositAmount() { return monthlyDepositAmount; }
	int getAccountPrefix() { return accountPrefix; }

	void setInterestRate(float ir) { interestRate = ir; }
	void setmonthlyDepositAmount(float mda) { monthlyDepositAmount = mda; }

	void show()
	{
		cout << "Loan Account\n";
		Account::show();
		cout << "Interest Rate          : " << interestRate << "\n";
		cout << "Monthly Deposit amount : " << monthlyDepositAmount << "\n";
		cout << "Account Prefix         : " << accountPrefix << "\n";
	}
};

class TwoYearMDS : public MonthlyDepositScheme
{
	int maximuminterest;

public:
	TwoYearMDS(int mx = 0)
	{
		MonthlyDepositScheme();
		maximuminterest = mx;
	}
	int getMaximumInterest()
	{
		return maximuminterest;
	}

	void setMaximumInterest(int mx)
	{
		maximuminterest = mx;
	}

	void show()
	{
		cout << "Two Year Deposit Scheme\n";
		MonthlyDepositScheme::show();
		cout << "Maximum Interest : " << maximuminterest << "\n";
	}
};

class FiveYearMDS : public MonthlyDepositScheme
{
	int maximuminterest;

public:
	FiveYearMDS(int mx = 0)
	{
		MonthlyDepositScheme();
		maximuminterest = mx;
	}
	int getMaximumInterest()
	{
		return maximuminterest;
	}

	void setMaximumInterest(int mx)
	{
		maximuminterest = mx;
	}

	void show()
	{
		cout << "Five Year Deposit Scheme\n";
		MonthlyDepositScheme::show();
		cout << "Maximum Interest : " << maximuminterest << "\n";
	}
};

class InitialDepositMDS : public MonthlyDepositScheme
{
	int maximuminterest;
	int initialDepositAmont;

public:
	InitialDepositMDS(int mxi = 0, int init = 0)
	{
		MonthlyDepositScheme();
		maximuminterest = mxi;
		initialDepositAmont = init;
	}
	int getMaximumInterest()
	{
		return maximuminterest;
	}

	int getInitialDepositAmont()
	{
		return initialDepositAmont;
	}

	void setInitialDepositAmont(int init)
	{
		initialDepositAmont = init;
	}

	void setMaximumInterest(int mx)
	{
		maximuminterest = mx;
	}

	void show()
	{
		cout << "Initial Deposit Scheme\n";
		MonthlyDepositScheme::show();
		cout << "Initial Deposit Amount : " << initialDepositAmont << "\n";
		cout << "Maximum Interest       : " << maximuminterest << "\n";
	}
};

#endif
