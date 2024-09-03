#include "library.hpp"
#include <iostream>
int main()
{
    system("clear");
    int capacity;
    std::cout << "Enter the capacity of the library: ";
    std::cin >> capacity;
    Library library(capacity);
    int choice;
    while (true)
    {
        system("clear");
        std::cout << "1. Add book\n2. Display books\n3. Search book\n4. Delete book\n5. Return book\n6. Issue book\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.deleteBook();
            break;
        case 5:
            library.returnBook();
            break;
        case 6:
            library.issueBook();
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid choice\n";
        }
    }
    return 0;
}