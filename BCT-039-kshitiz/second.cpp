/*Create a class employee with employee id ,name and salary as data members.Implement function to 
input data from user and display employees who have salary greater than user specified amount*/
#include<iostream>
using namespace std;
class employee
{
    public:
    int empid;
    float sal;
    string name;
    float specsal=20000.0;
    class empid{};
    void getdata()
    {
        cout<<"Enter emloyee id"<<endl;
        cin>>empid;
        cout<<"Enter the employee name."<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the salary of the employee"<<endl;
        cin>>sal;
        cout<<endl;
    }
    void displaydata()
    {
        if(sal>specsal)
        {
            cout<<"Empployee id: "<<empid<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Salary: "<<sal<<endl<<endl;
        }
    }
};
int main()
{
    system("cls");
    int n,i,j,c=0;
    cout<<"Enter the total number of employees"<<endl;
    cin>>n;
    employee emp[n];
    cout<<"Enter the employee details."<<endl;
    for( i=0;i<n;i++)
    {
        
    }

    label1:  // using go to statement.
    try
    {    
    for( i=c;i<n;i++)
    {
        c=i;
        emp[i].getdata();
    if(i>0)
        {
            for(int j=0;j<i;j++)
            {
                if(emp[j].empid==emp[j+1].empid) //checking whether the employee is same or not.
                    {
                        throw emp[i];
                    }
            }        
        }
    }
    cout<<"Employee Details:"<<endl;
     for(int i=0;i<n;i++)
    {
        emp[i].displaydata();
    }
    }

    catch(...)
    {
        cout<<"Id cannot be same."<<endl;
        goto label1;
    }
    return 0;
}