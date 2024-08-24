#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>

class Book{
    private:
    std::string title;
    std::string author;
    int numberOfCopies;
    int issued;
    public:
    Book();
    Book(std::string title, std::string author, int numberOfCopies);
    void set();
    void display();
    std::string getTitle();
    void returnBook();
    void issue();
    int getNumberOfCopies();
    int getNumberOfIssued();
};

#endif// BOOK_HPP