#include "employee.hpp"
void allocateMemory(Employee **p, int n);
void deallocateMemory(Employee **p);
void getInput(Employee *p, int n);
void showEmployeeWithHigherSalaryThen(Employee *p, int n, double salary);

int main()
{
    Employee *p;
    int n;
    std::cout << "Enter number of employees: ";
    std::cin >> n;
    allocateMemory(&p, n);
    getInput(p, n);
    double salary;
    std::cout << "Enter salary to find employees with higher salary: ";
    std::cin >> salary;
    showEmployeeWithHigherSalaryThen(p, n, salary);
    deallocateMemory(&p);
    return 0;
}

void allocateMemory(Employee **p, int n)
{
    *p = new Employee[n];
}

void deallocateMemory(Employee **p)
{
    delete[] *p;
    *p = nullptr;
}

void getInput(Employee *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter details of employee " << i + 1 << std::endl;
        p[i].set();
    }
}

void showEmployeeWithHigherSalaryThen(Employee *p, int n, double salary)
{
    int count = 0;
    std::cout << "Employees with salary higher than " << salary << " are: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (p[i].getSalary() > salary)
        {
            p[i].show();
            std::cout << "---------------------------" << std::endl;
            count++;
        }
    }
    std::cout << "Total employees with salary higher than " << salary << " are: " << count << std::endl;
}