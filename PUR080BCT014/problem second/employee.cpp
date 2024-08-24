#include "employee.hpp"

Employee::Employee() {}
Employee::Employee(std::string name, std::string id, double salary)
{
    this->name = name;
    this->id = id;
    this->salary = salary;
}
void Employee::set()
{
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Enter id: ";
    std::cin >> id;
    std::cout << "Enter salary: ";
    std::cin >> salary;
}
void Employee::show()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Salary: " << salary << std::endl;
}

double Employee::getSalary()
{
    return salary;
}