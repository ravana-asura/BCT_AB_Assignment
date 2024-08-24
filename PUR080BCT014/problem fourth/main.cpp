#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override {
        double interest = amount * interestRate;
        balance += amount + interest;
        cout << "Deposited: " << amount << " with interest: " << interest << endl;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, double limit)
        : Account(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

int main() {
    Account* accounts[2];


    accounts[0] = new SavingsAccount(101, 1000.0, 0.05);  // Account with 5% interest rate
    accounts[1] = new CheckingAccount(102, 500.0, 200.0); // Account with RS200 overdraft limit

    accounts[0]->deposit(200.0);
    accounts[1]->deposit(150.0);

    accounts[0]->withdraw(100.0);
    accounts[1]->withdraw(600.0);

    accounts[0]->displayBalance();
    accounts[1]->displayBalance();

    // Clean up memory
    delete accounts[0];
    delete accounts[1];

    return 0;
}
