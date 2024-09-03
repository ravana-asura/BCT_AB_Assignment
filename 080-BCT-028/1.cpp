// Create a class person with name and date of birth as data members. Ask the user to enter a date of birth and print all persons name with a matched date of birth.

#include<iostream>
using namespace std;

class Date{
    int year;
    int month;
    int day;

    public:
        void dateInput(){
            cin >> year >> month >> day;
        }

        void dateOutput(){
            cout << year << "/" << month << "/" << day;
        }

        bool operator==(Date &d){
            return(year == d.year && month == d.month && day == d.day);
        }
};

class Person{
    char name[30];
    Date DOB;

    public:
        void getInput(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter DOB (YYYY/MM/DD): ";
            DOB.dateInput();
        }

        void showOutput(){
            cout << "Name: " << name << endl;
            cout << "Date of Birth: ";
            DOB.dateOutput();
            cout << endl;
        }

        friend void match(Date, Person);
};

void match(Date d, Person p){
    if(d == p.DOB){
        p.showOutput();
    }
}

int main(){
    int n;
    cout << "Enter no. of people: ";
    cin >> n;
    Person *p = new Person[n];

    cout << "Enter info of " << n << " people" << endl;
    for(int i=0; i<n; i++){
        p[i].getInput();
    }

    Date dob;
    cout << "Enter a DOB: ";
    dob.dateInput();

    cout << "People with matching birth date:" << endl;
    for(int i=0; i<n; i++){
        match(dob, p[i]);
    }
    delete [] p;
}