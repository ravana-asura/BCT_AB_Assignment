#include<iostream>
using namespace std;
class person{
    char name[30];
    int dob;
    public:
    person()
    {
        name[0] = '\0' ;
        dob = 0;
    }
    void getinfo(){
        cout<<"Enter Your Name and Dob"<<endl;
        cin>>name>>dob;
    }
    void showinfo()
    {
        cout<<name<<endl;
    }
    bool retdob(int b)
    {
        if(b==dob)
        return true;
        else
        return false;
    }
};
int main()
{
    person *p;
    int n,dob;
    cout<<"Enter the number of persons:";
    cin>>n;
    p = new person[n];
    for(int i = 0;i<n;i++)
    {
        p[i].getinfo();
    }
    cout<<"Enter Your Date of Birth:";
    cin>>dob;
    for(int i = 0;i<n;i++)
    {
        if(p[i].retdob(dob))
            p[i].showinfo();
    }
    delete[] p;
    return 0;
}
