
#include <iostream>
using namespace std;
class Account 
{
    protected:
    int accnum;
    double balance;
    public:
    Account(int accNum, double bal) : accnum(accNum), balance(bal) {} //member initializer list
    virtual ~Account() {}
    // Pure virtual functions 
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void  display() const
    {
        cout << "Account Number: " << accnum << endl;
        cout << "Balance: " << balance<<endl;
    }
};
// Derived class for savings account
class SavingsAccount : public Account
 {
    public:
    SavingsAccount(int accNum, double bal) : Account(accNum, bal) {}
    void deposit(double amount) override {
        if (amount > 0) {
            balance = balance+amount;
            cout << "Deposited " << amount << " into Savings Account.\n";
         }
          else 
        {
            cout << "Invalid deposit amount.\n";
        }
    }
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from Savings Account.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
    void display() const override {
        cout << "Savings ";
        Account::display();
    }
};

// Derived class for checking account
class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal) : Account(accNum, bal) {}

    void deposit(double amount) override {
        if (amount > 0)
         {
            balance= balance+amount;
            cout << "Deposited " << amount << " into Checking Account.\n";
        } 
        else {
            cout << "Invalid deposit amount.\n";
        }
    }
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance= balance-amount;
            cout << "Withdrew " << amount << " from Checking Account.\n";
        } 
        else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
    void display() const override {
        cout << "Checking ";
        Account::display();
    }
};
int main() {
    system("cls");
    int accnum;
    double intbal;
    char acctype;
    double amount;
    int choice;
    cout << "Enter account number: ";
    cin >> accnum;
    cout << "Enter initial balance: ";
    cin >> intbal;
    cout << "Enter account type (s for Savings, c for Checking): ";
    cin >> acctype;

    // Create account object based on type
    Account* accptr = nullptr;
    if (acctype == 's' || acctype == 'S') {
        accptr = new SavingsAccount(accnum, intbal);
    } 
    else if (acctype == 'c' || acctype == 'C')
     {
        accptr = new CheckingAccount(accnum, intbal);
    }
     else {
        cout << "Invalid account type. Exiting...\n";
        return 1;
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
         switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                accptr->deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                accptr->withdraw(amount);
                break;

            case 3:
                accptr->display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    delete accptr;
    return 0;
}