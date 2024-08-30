#include <iostream>
#include <cstring> // for string operations
using namespace std;

class Library {
    char bookTitle[100];
    char author[30];
    int noOfCopies;

public:
    // Constructor to initialize book details
    Library(const char* title = "", const char* auth = "", int copies = 0) {
        strncpy(bookTitle, title, sizeof(bookTitle) - 1);
        bookTitle[sizeof(bookTitle) - 1] = '\0';
        strncpy(author, auth, sizeof(author) - 1);
        author[sizeof(author) - 1] = '\0';
        noOfCopies = copies;
    }

    // Method to display book details
    void displayBook() const {
        cout << "Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << noOfCopies << endl;
    }

    // Method to add books
    void addBooks(int copiesToAdd) {
        noOfCopies += copiesToAdd;
        cout << "Added " << copiesToAdd << " copies. Total copies now: " << noOfCopies << endl;
    }

    // Method to issue a book
    void issueBook() {
        if (noOfCopies > 0) {
            noOfCopies--;
            cout << "Book issued successfully. Remaining copies: " << noOfCopies << endl;
        } else {
            cout << "No copies available to issue." << endl;
        }
    }

    // Method to return a book
    void returnBook() {
        noOfCopies++;
        cout << "Book returned successfully. Total copies now: " << noOfCopies << endl;
    }
};

int main() {
    Library book("The Great Gatsby", "F. Scott Fitzgerald", 5); // Initialize with one book

    int choice, copies;
    
    cout << "WELCOME TO THE VIRTUAL LIBRARY." << endl;
    
    while (true) {
        cout << "\nEnter what you want to do:" << endl;
        cout << "1. Display Book Details" << endl;
        cout << "2. Add Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                book.displayBook();
                break;

            case 2:
                cout << "Enter number of copies to add: ";
                cin >> copies;
                book.addBooks(copies);
                break;

            case 3:
                book.issueBook();
                break;

            case 4:
                book.returnBook();
                break;

            case 5:
                cout << "Thank you for visiting! Goodbye." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
