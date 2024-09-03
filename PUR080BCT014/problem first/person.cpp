#include "person.hpp"

Person::Person() {}
Person::Person(std::string name, DOB dob)
{
    this->name = name;
    this->dob = dob;
}

void Person::set()
{
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    dob.set();
}

void Person::show()
{
    std::cout << "Name: " << name << std::endl;
    dob.show();
}

DOB Person::getDob()
{
    return dob;
}