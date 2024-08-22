/*Create a class person with its data members name and date of birth.
Ask user to enter the name and date of birth and print all person name with matched date of birth*/
#include<iostream>
using namespace std;
#include<string.h>
class year{}; // exception class
class month{}; // exception class
class day{}; // exception class
class person
{
    int dob[3],i=0;
    string name;
    public:
    void getdata()
    {
        cout<<"Enter the name of the person."<<endl;
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the date of birth"<<endl;
        cout<<"Enter the year"<<endl;
        cin>>dob[i];
        cout<<"Enter the month"<<endl;
        cin>>dob[i+1];
        cout<<"Enter the day"<<endl;
        cin>>dob[i+2];
        cout<<endl;
        if(dob[i+1]>12)
        {
            throw month();
        }
        else if((dob[i+2]>32))
        {
            throw day();
        }
        else if(dob[i]<0)
        {
            throw year();
        }
    }
    void display()
    {
            cout<<"Name:"<<name<<endl;
            cout<<"DOB:  "<<dob[i]<<" / "<<dob[i+1]<<" / "<<dob[i+2]<<endl<<endl;
    }
};
int main()
{
    system("cls");
    int n,i,j,c=0;
    cout<<"Enter the number of person:"<<endl;
    cin>>n;
    person obj[n];
    label1:try
    {
    for(i=c;i<n;i++)
    {
        c=i;
        obj[i].getdata();
    }
    }
    catch(day)
    {
        cout<<"Day cannot be greater than 32"<<endl;
        goto label1;
    }
    catch(month)
    {
         cout<<"Month cannot be greater than 12"<<endl;
        goto label1;
    }
    catch(year)
    {
        cout<<"Year cannot be negative"<<endl;
        goto label1;
    }
    cout<<"The name and date of birth of the person is:"<<endl;
    for(i=0;i<n;i++)
    {
    obj[i].display();
    }
    return 0;
}