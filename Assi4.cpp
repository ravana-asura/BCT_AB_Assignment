#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

class Account {
protected:
    int accountNo;
    float balance;

public:
    Account() {
        accountNo = rand() % 1000000; 
        balance = 0.0f;
    }

    virtual ~Account() {}

    virtual void deposit(float amount) = 0; 
    virtual void withdraw(float amount) = 0; 

    float getBalance() const {
        return balance;
    }

    int getAccountNo() const {
        return accountNo;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount() : Account() {}

    void deposit(float amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs:" << amount << " to Savings Account. New balance is Rs:" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs:" << amount << " from Savings Account. Remaining balance is Rs:" << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount() : Account() {}

    void deposit(float amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs:" << amount << " to Checking Account. New balance is Rs:" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(float amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs:" << amount << " from Checking Account. Remaining balance is Rs:" << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    const int NUM_ACCOUNTS = 5;
    Account* accounts[NUM_ACCOUNTS];
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        if (i % 2 == 0) {
            accounts[i] = new SavingsAccount();
        } else {
            accounts[i] = new CheckingAccount();
        }
    }

    int choice, accountIndex;
    float amount;

    while (true) {
        cout << "\nSelect an option:\n";
        cout << "1. Deposit money\n";
        cout << "2. Withdraw money\n";
        cout << "3. View account balances\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Select account index (0 to " << NUM_ACCOUNTS - 1 << "): ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < NUM_ACCOUNTS) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[accountIndex]->deposit(amount);
                } else {
                    cout << "Invalid account index." << endl;
                }
                break;

            case 2:
                cout << "Select account index (0 to " << NUM_ACCOUNTS - 1 << "): ";
                cin >> accountIndex;
                if (accountIndex >= 0 && accountIndex < NUM_ACCOUNTS) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[accountIndex]->withdraw(amount);
                } else {
                    cout << "Invalid account index." << endl;
                }
                break;

            case 3:
                cout << "Account balances:\n";
                for (int i = 0; i < NUM_ACCOUNTS; ++i) {
                    cout << "Account " << i << " (No: " << accounts[i]->getAccountNo() << "): Rs:" << accounts[i]->getBalance() << endl;
                }
                break;

            case 4:
             
                for (int i = 0; i < NUM_ACCOUNTS; ++i) {
                    delete accounts[i];
                }
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
