/*2.Design a class Employee with id, name, and salary as data members. Implement
functions to input employee data and display employees who have a salary greater
than a user-specified amount.*/

#include<iostream>
using namespace std;

class Employee{

    int id;
    char name[30];
    float salary;

    public:

    void getdata(){
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter salary: ";
        cin>>salary;
    }

    void show(){
        cout<<"ID: "<<id<<"      "<<"Name: "<<name<<"      "<<"Salary: "<<salary<<endl;
    }

    float getSal(){
        return salary;
    }
};

int main(){

    int n;
    cout<<"Enter the no. of employees:"<<endl;
    cin>>n;

    Employee *e= new Employee[n];

    cout<<"Enter the details of "<<n<<" employees:"<<endl;

    for(int i=0 ; i<n ; i++){
        e[i].getdata();
    }
    float sal;
    cout<<"Enter specified salary:";
    cin>>sal;
    for(int i=0; i<n ; i++){
        if(e[i].getSal()>sal)
        e[i].show();
    }

    delete[] e;
    return 0;
}