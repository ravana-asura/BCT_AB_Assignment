// Create a base class Account with data members accountNumber and balance. Derive two classes Savings Account and CheckingAccount from Account. Implement polymorphic behavior where the base class pointer can point to objects of derived classes, and call their respective member functions to deposit and withdraw money, applying specific rules for each account type.

#include<iostream>

#define n 5

using namespace std;

class Account{
    protected:
        int accountNumber;
        float balance;

    public:
        Account(int accNum){
            accountNumber = accNum;
            balance = 0;
        }

        int getAccountNumber() const {
            return accountNumber;
        }

        virtual void deposit() = 0;
        virtual void withdraw() = 0;

        virtual ~Account(){}
};

class CheckingAccount : public Account{
    float withdrawalLimit = 100000;
    public:
        CheckingAccount(int accNum) : Account(accNum) {}

        void deposit() override{
            float amt;
            cout << "Enter the amount to deposit to account " << accountNumber << ": ";
            cin >> amt;
            balance += amt;
            cout << "Deposited " << amt << ". New balance: " << balance << endl;
        }
        void withdraw() override{
            float amt;
            cout << "Enter the amount to withdraw from account " << accountNumber << ": ";
            cin >> amt;
            if(amt > withdrawalLimit){
                cout << "Sorry, you cannot withdraw more than " << withdrawalLimit << " at once." << endl;
            } else {
                if(balance < amt){
                    cout << "Insufficient Balance." << endl;
                } else {
                    balance -= amt;
                    cout << "Withdrawn " << amt << ". New balance: " << balance << endl;
                }
            }
        }
};

class SavingsAccount : public Account{
    int withdrawalLimit = 6;
    float penalty = 0.01;
    public:
        SavingsAccount(int accNum) : Account(accNum) {}

        void deposit() override{
            float amt;
            cout << "Enter the amount to deposit to account " << accountNumber << ": ";
            cin >> amt;
            balance += amt;
            cout << "Deposited " << amt << ". New balance: " << balance << endl;
        }

        void withdraw() override{
            float amt;
            cout << "Enter the amount to withdraw from account " << accountNumber << ": ";
            cin >> amt;
            if (withdrawalLimit > 0){
                if(balance > amt){
                    withdrawalLimit--;
                    balance -= amt;
                    cout << "Withdrawn " << amt << ". New balance: " << balance << endl;
                } else {
                    cout << "Insufficient Balance." << endl;
                }
            } else {
                char ch;
                cout << "You have reached your withdrawal limit. If you still wish to continue, a 1% penalty will be charged from your account. Do you wish to continue(y/n): ";
                cin >> ch;
                if(ch == 'y'){
                    balance -= amt * (1 + penalty);
                    cout << "Withdrawn " << amt << " with penalty. New balance: " << balance << endl;
                } else {
                    cout << "Transaction cancelled!" << endl;
                }
            }
        }
};

int main(){
    Account *aPtr[n];
    int accNum;
    char accType;

    for(int i=0; i<n; i++){
        cout << "Enter account number for account " << i+1 << ": ";
        cin >> accNum;
        cout << "Is this a Savings account or Checking account? (s/c): ";
        cin >> accType;

        if(accType == 's'){
            aPtr[i] = new SavingsAccount(accNum);
        } else {
            aPtr[i] = new CheckingAccount(accNum);
        }
    }

    for(int i=0; i<n; i++){
        cout << "\nSelect an account number to deposit to: ";
        cin >> accNum;
        for(int j=0; j<n; j++){
            if(aPtr[j]->getAccountNumber() == accNum){
                aPtr[j]->deposit();
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << "\nSelect an account number to withdraw from: ";
        cin >> accNum;
        for(int j=0; j<n; j++){
            if(aPtr[j]->getAccountNumber() == accNum){
                aPtr[j]->withdraw();
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        delete aPtr[i];
    }

    return 0;
}