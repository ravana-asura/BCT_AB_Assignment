#include <iostream>
using namespace std;

const int maxwithdraw = 3;  
const float withdrawfee = 2.0;         
const float overdraft = 100.0;

class Account {
protected:
    int accountnumber;
    float balance;

public:
    virtual void details() = 0; 
    virtual void deposit() = 0; 
    virtual void withdraw() = 0;
    virtual void showdetails() = 0;
    virtual ~Account() {} 
};

class SavingAccount : public Account {
private:
    float minimumBalance;
    int withdrawalCount;
    float feePerExcessWithdrawal;

public:
    SavingAccount(float minBalance)
        : minimumBalance(minBalance), withdrawalCount(0), feePerExcessWithdrawal(withdrawfee) {}

    void details() {
        cout << "Enter account number: ";
        cin >> accountnumber;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter the amount you want to deposit: ";
        cin >> amount;
        balance += amount;
    }

    void withdraw() {
        float amount;
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        if (withdrawalCount >= maxwithdraw) {
            cout << "Withdraw limit reached. A fee of " << feePerExcessWithdrawal << " will be applied." << endl;
            balance -= feePerExcessWithdrawal;
        }
        if (balance - amount < minimumBalance) {
            cout << "Insufficient balance. Withdraw would be below minimum balance." << endl;
        } else {
            balance -= amount;
            withdrawalCount++;
            cout << "Withdraw successfully." << endl;
        }
    }

    void showdetails() {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Withdraws This Month: " << withdrawalCount << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount() : overdraftLimit(overdraft) {}

    void details() {
        cout << "Enter account number: ";
        cin >> accountnumber;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter the amount you want to deposit: ";
        cin >> amount;
        balance += amount;
    }

    void withdraw() {
        float amount;
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        if (balance - amount < -overdraftLimit) {
            cout << "Insufficient funds. Withdraw would exceed overdraft limit." << endl;
        } else {
            balance -= amount;
            cout << "Withdraw successfully." << endl;
        }
    }

    void showdetails() {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account* account = nullptr;
    int type;
    int n;

    cout << "\nSelect the account type\n1. Saving Account\n2. Checking Account" << endl;
    cin >> type;

    switch (type) {
    case 1:
        account = new SavingAccount(100.0);
        break;
    case 2:
        account = new CheckingAccount(); 
        break;
    default:
        cout << "Invalid Input." << endl;
        return 1;
    }

    account->details();
    while (true) {
        cout << "\nEnter your choice\n1. Deposit Money\n2. Withdraw Money\n3. View Details\n4. Exit" << endl;
        cin >> n;
        switch (n) {
        case 1:
            account->deposit();
            break;
        case 2:
            account->withdraw();
            break;
        case 3:
            account->showdetails();
            break;
        case 4:
            delete account;
            return 0;
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
}
