#include "dob.hpp"

DOB::DOB() {}
DOB::DOB(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}
void DOB::set()
{
    std::cout<<"Enter date of birth."<<std::endl;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter day: ";
    std::cin >> day;
}

void DOB::show()
{
    std::cout << "DOB: " << year << "/" << month << "/" << day << std::endl;
}

bool DOB::operator==(DOB &dob)
{
    return (this->year == dob.year && this->month == dob.month && this->day == dob.day);
}
