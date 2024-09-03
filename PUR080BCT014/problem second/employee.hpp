#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
class Employee{
    private:
    std::string name;
    std::string id;
    double salary;

    public:
    Employee();
    Employee(std::string name, std::string id, double salary);
    void set();
    void show();
    double getSalary();
};

#endif // EMPLOYEE_HPP