#ifndef DOB_HPP
#define DOB_HPP
#include <iostream>
class DOB{
    private:
    int year;
    int month;
    int day;
    public:
    DOB();
    DOB(int year,int month, int day);
    void show();
    void set();
    bool operator == (DOB &dob);
};
#endif // DOB_HPP