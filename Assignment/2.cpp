#include<iostream>
using namespace std;
class Employee 
{
    int id;
    char name[20];
    float salary;
    public:
    void input()
    {
        cout<<"Enter your id : ";
        cin>>id;
        cout<<"Enter your name : ";
        cin>>name;
        cout<<"Enter your salary : ";
        cin>>salary;
    }
    void calculate(int a)
    {
        if(salary>a)
        {
            cout<<"Id : " <<id<<endl<<"Name : "<<name<<endl<<"Salary : "<<salary<<endl;
        }
    }
};
int main()
{
    int n,reqsal;
    cout<<"How many data do you want : ";
    cin>>n;
    Employee e[n];
    for(int i = 0; i < n; i++)
    {
        e[i].input();
    }
    cout<<"Enter the amount to display salary : ";
    cin>>reqsal;
    for(int i = 0; i < n; i++)
    {
        e[i].calculate(reqsal);
    }
}