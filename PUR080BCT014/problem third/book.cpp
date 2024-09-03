#include "book.hpp"

Book::Book(){
    title = "";
    author = "";
    numberOfCopies = 0;
    issued = 0;

}

Book::Book(std::string title, std::string author,int numberOfCopies){
    this->title = title;
    this->author = author;
    this->numberOfCopies = numberOfCopies;
}

void Book::set(){
    std::cout<<"Enter the title of the book: ";
    std::getline(std::cin>>std::ws,title);
    std::cout<<"Enter the author of the book: ";
    std::getline(std::cin>>std::ws,author);
    std::cout<<"Enter the number of copies: ";
    std::cin>>numberOfCopies;
}

void Book::display(){
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Number of available copies: " << numberOfCopies << std::endl;
}

std::string Book::getTitle(){
    return title;
}

void Book::returnBook(){
    numberOfCopies++;
    issued--;
}

int Book::getNumberOfCopies(){
    return numberOfCopies;
}

void Book::issue(){
    numberOfCopies--;
    issued++;
}

int Book::getNumberOfIssued(){
    return issued;
}