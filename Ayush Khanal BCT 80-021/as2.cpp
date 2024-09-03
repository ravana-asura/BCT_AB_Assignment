#include<iostream>
using namespace std;
class employee{
    int id,salary;
    char name[30];
    public:
    employee():id(0),salary(0){name[0] = '\0';}
    void getinfo()
    {
        cout<<"Enter Your name , id and salary:"<<endl;
        cin>>name>>id>>salary;
    }
    void operator>(int n)
    {
        if(salary>n)
        cout<<"Name = "<<name<<"\t Id = "<<id<<endl;
    }
};
int main()
{
    employee *e;
    int n;
    cout<<"Enter number of employees:";
    cin>>n;
    e = new employee[n];
    for(int i = 0;i<n;i++)
    {
        e[i].getinfo();
    }
    for(int i = 0;i<n;i++)
    {
        e[i]>10000;
    }
    delete[] e;
    return 0;
}
