/*1. Create a class person with name and date of birth as data members. Ask the user to enter 
a date of birth and print all persons name with a matched date of birth.*/

#include<iostream>
using namespace std;

class person{
    char name[30];
    int year,month,day;

    public:

    void getData(){
        cout<<"Enter Name:";
        cin>>name;
        cout<<"Enter date of birth in YYYY-MM-DD formate:";
        cin>>year>>month>>day;

    }

    void showData(){
        cout<<"Name: "<<name<<endl<<"DOB: "<<year<<"-"<<month<<"-"<<day<<endl;
    }

    int getYear(){
        return year;
    }

    int getMonth(){
        return month;
    }

    int getDay(){
        return day;
    }
    friend void compare(person &p,int y,int m, int d);
};

void compare(person &p,int y, int m, int d){
   if(y==p.getYear() && m==p.getMonth() && d==p.getDay())
   p.showData();
}

int main(){
    
    int n;
    cout<<"Enter no. of persons:"<<endl;
    cin>>n;

    person *p = new person[n];

    cout<<"Enter the details of "<<n<<" persons:"<<endl;

    for(int i=0 ; i < n ; i++)
    p[i].getData();

    int y,m,d;

    cout<<"Enter the specific date of birth in YYYY-MM-DD formate:"<<endl;
    cin>>y>>m>>d;

    for(int i =0; i < n ;i++)
    compare(p[i],y,m,d);
    
    delete[] p;
    return 0;
}