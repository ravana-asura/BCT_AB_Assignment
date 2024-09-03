#include "library.hpp"

Library::Library()
{
    size = 0;
    capacity = 0;
    books = nullptr;
}

Library::Library(int capacity)
{
    this->capacity = capacity;
    size = 0;
    books = new Book[capacity];
}

void Library::addBook()
{
    if (size == capacity)
    {
        std::cout << "Library is full" << std::endl;
        std::cout << "press any key to return...";

        std::cin.ignore();
        std::cin.get();
        return;
    }
    books[size].set();
    size++;
}

void Library::displayBooks()
{
    if (size == 0)
    {
        std::cout << "Library is empty" << std::endl;
        std::cout << "press any key to continue...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    for (int i = 0; i < size; i++)
    {
        books[i].display();
    }
    std::cout << "press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Library::searchBook()
{
    if (size == 0)
    {
        std::cout << "Library is empty" << std::endl;
        std::cout << "press any key to continue...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::string title;
    std::cout << "Enter the title of the book: ";
    std::getline(std::cin >> std::ws, title);
    for (int i = 0; i < size; i++)
    {
        if (books[i].getTitle() == title)
        {
            books[i].display();
            std::cin.ignore();
            std::cin.get();
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
    std::cout << "press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Library::deleteBook()
{
    if (size == 0)
    {
        std::cout << "Library is empty" << std::endl;
        std::cout << "press any key to continue...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::string title;
    std::cout << "Enter the title of the book: ";
    std::getline(std::cin >> std::ws, title);
    for (int i = 0; i < size; i++)
    {
        if (books[i].getTitle() == title)
        {
            for (int j = i; j < size - 1; j++)
            {
                books[j] = books[j + 1];
            }
            size--;
            std::cout << "Book deleted" << std::endl;
            std::cout << "press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
    std::cout << "press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Library::returnBook()
{
    if (size == 0)
    {
        std::cout << "Library is empty" << std::endl;
        std::cin.ignore();
        std::cout << "press any key to continue...";
        std::cin.get();
        return;
    }
    std::string title;
    std::cout << "Enter the title of the book: ";
    std::getline(std::cin >> std::ws, title);
    for (int i = 0; i < size; i++)
    {
        if (books[i].getTitle() == title)
        {
            if (books[i].getNumberOfIssued() == 0)
            {
                std::cout << "book '" << books[i].getTitle() << "' is not issued." << std::endl;
                std::cout << "press any key to continue...";
                std::cin.ignore();
                std::cin.get();
                return;
            }
            books[i].returnBook();
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
    std::cin.ignore();
    std::cout << "press any key to return...";
    std::cin.get();
}

Library::~Library()
{
    delete[] books;
}

void Library::issueBook()
{
    if (size == 0)
    {
        std::cout << "Library is empty" << std::endl;
        std::cout << "press any key to continue...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::string title;
    std::cout << "Enter the title of the book: ";
    std::getline(std::cin >> std::ws, title);
    for (int i = 0; i < size; i++)
    {
        if (books[i].getTitle() == title)
        {
            if (books[i].getNumberOfCopies() == 0)
            {
                std::cout << "Book is currently not available" << std::endl;
                std::cout << "press any key to continue...";
                std::cin.ignore();
                std::cin.get();
                return;
            }
            std::cout << "Book " << books[i].getTitle() << " is issued successfully!!" << std::endl
                      << "Hppy Reading!!" << std::endl
                      << std::endl;
            std::cout << "press any key to continue...";
            std::cin.ignore();
            std::cin.get();
            books[i].issue();
            return;
        }
    }
    std::cout << "Book not found" << std::endl;
    std::cout << "press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}