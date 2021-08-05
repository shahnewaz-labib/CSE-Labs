#include <iostream>
#include "Accounts.hpp"
using namespace std;

int CurrentAccount::nextAccount = 0;
int SavingsAccount::nextAccount = 0;
int MonthlyDepositScheme::nextAccount = 0;
int LoanAccount::nextAccount = 0;

int main()
{
	CurrentAccount c;
	SavingsAccount s;
	LoanAccount l;
	TwoYearMDS t;
	FiveYearMDS f;
	InitialDepositMDS i;

	c.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";

	s.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";

	l.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";

	t.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";

	f.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";

	i.show();
    cout << "- - - - - - - - - - - - - - - - - -\n";


}
