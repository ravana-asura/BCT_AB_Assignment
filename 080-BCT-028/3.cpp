// Define a class Library with bookTitle, author, and numberOfCopies as data members. Implement methods to add new books, issue books, and return books. Ensure that the number of copies is appropriately updated for each operation.

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Library {
    string bookTitle;
    string author;
    int numberOfCopies = 0;

public:
    void getInfo() {
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;
    }

    void showInfo() const {
        cout << "Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "No. of copies: " << numberOfCopies << endl;
    }

    void add(int n) {
        numberOfCopies += n;
        cout << "Added " << n << " books.\n";
    }

    void issue() {
        if (numberOfCopies == 0) {
            cout << "Sorry, the book is currently unavailable." << endl;
        } else {
            numberOfCopies--;
            cout << "Book issued.\n";
        }
    }

    void returnBook() {
        numberOfCopies++;
        cout << "Book returned.\n";
    }

    string getTitle() const {
        return bookTitle;
    }
};

int main() {
    Library lib[100];
    int num;
    cout << "Enter number of books: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        cout << "Enter book details for book " << i + 1 << ":" << endl;
        lib[i].getInfo();
        cout << endl;
    }

    int ch, n;
    string title;

    while (true) {
        cout << "\nLIBRARY MENU\n";
        cout << "1. View Books\n2. Add Book\n3. Issue Book\n4. Return Book\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (int i = 0; i < num; i++) {
                    cout << "Book " << i + 1 << ":" << endl;
                    lib[i].showInfo();
                }
                break;

            case 2:
                cout << "Enter the title of the book to add copies: ";
                cin.ignore();
                getline(cin, title);
                for (int i = 0; i < num; i++) {
                    if (lib[i].getTitle() == title) {
                        cout << "Enter number of copies to add: ";
                        cin >> n;
                        lib[i].add(n);
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter the title of the book to issue: ";
                cin.ignore();
                getline(cin, title);
                for (int i = 0; i < num; i++) {
                    if (lib[i].getTitle() == title) {
                        lib[i].issue();
                        break;
                    }
                }
                break;

            case 4:
                cout << "Enter the title of the book to return: ";
                cin.ignore();
                getline(cin, title);
                for (int i = 0; i < num; i++) {
                    if (lib[i].getTitle() == title) {
                        lib[i].returnBook();
                        break;
                    }
                }
                break;

            case 5:
                exit(0);

            default:
                cout << "Please enter a valid choice." << endl;
        }
    }

    return 0;
}