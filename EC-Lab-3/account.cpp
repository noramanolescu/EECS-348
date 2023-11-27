#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
public:
    string accountNumber;
    string accountHolder;
    double balance;

    Account operator+=(Account &accountB) {
        Account accountA;
        accountA.accountNumber = accountNumber;
        accountA.accountHolder = accountHolder;
        double amount = 300; // transfer amount listed as $300 in assignment
        accountB.withdraw(amount);
        balance += amount;
        accountA.balance = balance;
        return accountA;
    }

    void displayDetails() {
        cout << "Account Details for Account (ID: " << accountNumber << ")" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << setprecision(2) << fixed << balance << endl;
        cout << "\n";
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < balance) {
            balance -= amount;
        } else {
            cout << "Withdrawal not completed. (Insufficient balance for withdrawal) " << endl;
        }
    }
};

class SavingsAccount: public Account {
public:
    double interestRate;

    void displayDetails() {
        cout << "Account Details for Savings Account (ID: " << accountNumber << ")" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << setprecision(2) << fixed << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "\n";
    }

    void withdraw(double amount) {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
        } else {
            cout << "Withdrawal not completed. (Withdrawal surpasses minimum amount) " << endl;
        }
    }

    void setMinimum(double amount) {
        minimumBalance = amount;
    }

private:
    double minimumBalance = 0;
};

class CurrentAccount: public Account {
public:
    double overdraftLimit;

    void displayDetails() {
        cout << "Account Details for Current Account (ID: " << accountNumber << ")" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << setprecision(2) << fixed << balance << endl;
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
        cout << "\n";
    }

    void withdraw(double amount) {
        if (balance - amount + overdraftLimit >= 0) {
            balance -= amount;
        } else {
            cout << "Withdrawal not completed. (Withdrawal surpasses overdraft limit)" << endl;
        }
    }
};

int main() {

    SavingsAccount savings;
    savings.accountNumber = "S123";
    savings.accountHolder = "John Doe";
    savings.balance = 1000;
    savings.interestRate = 0.02;

    CurrentAccount current;
    current.accountNumber = "C456";
    current.accountHolder = "Jane Doe";
    current.balance = 2000;
    current.overdraftLimit = 500;

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    cout << "Account Details after deposit and withdrawal: " << endl;
    savings.displayDetails();
    current.displayDetails();

    // Transferring $300 from savings to current
    current += savings;

    cout << "Account Details after transfer: " << endl;
    savings.displayDetails();
    current.displayDetails();

    return 0;
}