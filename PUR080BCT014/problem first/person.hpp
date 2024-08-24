#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include "dob.hpp"
class Person
{
private:
    std::string name;
    DOB dob;
public:
    Person();
    Person(std::string name, DOB dob);
    void set();
    void show();
    DOB getDob();
};
#endif // PERSON_HPP