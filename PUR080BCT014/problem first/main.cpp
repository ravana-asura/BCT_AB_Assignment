#include "person.hpp"
void allocateMemory(Person **p, int n);
void deallocateMemory(Person **p);
void getInput(Person *p, int n);
Person findwithDoB(Person *p, DOB dob, int n);
int main()
{
    Person *p;
    int n;
    std::cout << "Enter number of persons: ";
    std::cin >> n;
    allocateMemory(&p, n);
    getInput(p, n);
    DOB dob;
    std::cout << "Find perosn with DoB:" << std::endl;
    dob.set();
    Person foundPerson = findwithDoB(p, dob, n);
    std::cout << "Person found with given DoB is:" << std::endl;
    foundPerson.show();
    deallocateMemory(&p);
    return 0;
}

void allocateMemory(Person **p, int n)
{
    *p = new Person[n];
}

void deallocateMemory(Person **p)
{
    delete[] *p;
    *p = nullptr;
}

void getInput(Person *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter details of person " << i + 1 << std::endl;
        p[i].set();
    }
}

Person findwithDoB(Person *p, DOB dob, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].getDob() == dob)
        {
            return p[i];
        }
    }
    std::cout << "No person found with given DoB" << std::endl;
    deallocateMemory(&p);
    if (p != nullptr)
        delete[] p;
    else
    {
        std::cout << "Memory deallocated" << std::endl;
    }
    exit(0);
}