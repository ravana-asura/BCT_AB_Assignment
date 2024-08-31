// 1.Create a class person with name and date of birth as data members.
// Ask the user to enter a date of birth and print all person name
// with a matched date of birth.

#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char name[30];
    char dob[11]; // Assuming the format is dd-mm-yyyy
public:
    void getInput() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the date of birth (dd-mm-yyyy): ";
        cin >> dob;
    }
    void getOutput()  {
        cout << "Name: " << name << endl;
    }
    bool check( char Dob[])  {
        return strcmp(dob, Dob) == 0;
    }
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    Person p[100];
    for(int i = 0; i < n; i++) {
        p[i].getInput();
    }

    char Dob[11];
    cout << "Enter the date of birth to search for (dd-mm-yyyy): ";
    cin >>Dob;

    bool found = false;
    for(int i = 0; i < n; i++) {
        if(p[i].check(Dob)) {
            p[i].getOutput();
            found = true;
        }
    }

    if(!found) {
        cout << "No person found with the given date of birth." << endl;
    }

    return 0;
}
