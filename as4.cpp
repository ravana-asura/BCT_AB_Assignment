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
        cout << "Deposited: " << amount << " New Balance: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    virtual ~Account() {}
};
class SavingsAccount : public Account {
public:
    SavingsAccount(int accNum, double bal) : Account(accNum, bal) {}
    void deposit(double amount) override {
        balance += amount + (amount * 0.02);  // 2% interest on deposit
        cout << "Deposited with interest: " << amount << " New Balance: " << balance << endl;
    }
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {}
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};
int main() {
    Account* acc1 = new SavingsAccount(1001, 500.0);
    Account* acc2 = new CheckingAccount(1002, 1000.0);
    acc1->deposit(200);
    acc1->withdraw(100);
    acc2->deposit(300);
    acc2->withdraw(500);
    delete acc1;
    delete acc2;
    return 0;
}
