#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "book.hpp"
#include <iostream>
class Library
{
private:
    Book *books;
    int size;
    int capacity;
public:
    Library();
    Library(int capacity);
    void addBook();
    void displayBooks();
    void searchBook();
    void deleteBook();
    void returnBook();
    void issueBook();
    ~Library();
};
#endif // LIBRARY_HPP