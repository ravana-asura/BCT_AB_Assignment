// Design a class Employee with id,name,and salary as data members.Implement 
// functions to input Employee data and display Employee who have a salary greater
// than a user specified amount.
#include <iostream>
using namespace std;

class Employee {
    int id;
    char name[30];
    int  salary;
    public:
    void getinput(){
        cout<<"Enter id ,name and salay:";
        cin>>id>>name>>salary;
    }

    void getoutput(){
        cout<<"The details:"<<endl;
        cout<<"ID="<<id<<endl;
                cout<<"Name="<<name<<endl;
                        cout<<"Salary="<<salary<<endl;


    }
    int  getsal(){return salary;}
    // void check(int sal){
    //     int t;

    // }

};

int main(){
    Employee e[100];
    int sal,n;
    cout<<"Enter the number of employee:";
    cin>>n;

        
    for(int i=0;i<n;i++){
        e[i].getinput();
    }
         
    cout<<"Enter the salary you want:";
    cin>>sal;
    for(int i=0;i<n;i++){

        if(e[i].getsal()>sal){

        e[i].getoutput();
        }
    }
    






    
}