#include <iostream>
#include <cstring>
using namespace std;
class Library {
    char bookTitle[30];
    char author[30];
    int numberOfCopies;

public:
    Library() {
        strcpy(bookTitle, "Unknown");
        strcpy(author, "Unknown");
        numberOfCopies = 0;
    }
    void addBook(const char* title, const char* authorName, int copies) {
        strcpy(bookTitle, title);
        strcpy(author, authorName);
        numberOfCopies = copies;
    }
    void issueBook() {
        if (numberOfCopies > 0) {
            numberOfCopies--;
            cout << "Book issued successfully. Copies left: " << numberOfCopies << endl;
        } else {
            cout << "No copies left to issue." << endl;
        }
    }
    void returnBook() {
        numberOfCopies++;
        cout << "Book returned successfully. Total copies: " << numberOfCopies << endl;
    }
    void displayBookInfo(){
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
    }
};
int main() {
    Library lib;
    lib.addBook("Quantum", "Manjit Kumar", 10);
    lib.displayBookInfo();
    lib.issueBook();
    lib.returnBook();
    return 0;
}
