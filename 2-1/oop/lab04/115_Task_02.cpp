#include <iostream>
using namespace std;

enum accType { Savings, Current };

class BankAccount {
    string acc_number, acc_holder_name;
    accType acc_t;
    double cur_bal, min_bal;
public:
    BankAccount() {}

    BankAccount(string acc_n, string acc_h_n, accType t, double cur_balance, double min_balance) {
        acc_number = acc_n;
        acc_holder_name = acc_h_n;
        acc_t = t;
        cur_bal = cur_balance;
        min_bal = min_balance;

    }

    ~BankAccount() {
        cout << "Account of Mr. " << acc_holder_name << " with account no " << acc_number << " is destroyed with a balance of BDT " << cur_bal << "\n";
    }

    void setAccHolderName(string name) {
        acc_holder_name = name;
    }

    void setAccNumber(string num) {
        acc_number = num;
    }

    void setAccType(accType type) {
        acc_t = type;
    }

    void setCurBal(double bal) {
        cur_bal = bal;
    }

    void setMinBal(double bal) {
        min_bal = bal;
    }

    void showInfo() {
        cout << "Account Number : " << acc_number << "\n";
        cout << "Account Holder : " << acc_holder_name << "\n";
        cout << "Account type   : " << (acc_t == accType::Savings ? "Savings" : "Current") << "\n";
        cout << "Current Balance: " << cur_bal << "\n";
        cout << "Minimum Balance: " << min_bal << "\n";
    }

    void showBalance() {
        cout << "Balance : " << cur_bal << "\n";
    }

    void deposit(double amount) {
        cur_bal += amount;
    }

    void withdraw(double amount) {
        if(cur_bal - amount < min_bal) {
            cout << "ERROR! Withdrawal failed due to low account balance!\n";
        }
        cur_bal += amount;
    }

    void giveInterest(double rate = 2.5) {
        cur_bal += cur_bal*rate*0.9/100;
    }

};


int main() {
     BankAccount b("1234", "labib", accType::Savings, 10000, 5000);
     b.showInfo();
     b.deposit(1200);
     b.withdraw(10000);
     b.showInfo();
}
