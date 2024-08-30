#include <iostream>
using namespace std;
class Person
{
    char name[10];
    int year, month, day;

public:
    void input()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your date of birth (YY MM DD format) : ";
        cin >> year >> month >> day;
    }
    void match(int yr, int mon, int da)
    {
        if (yr == year &&mon == month &&da == day)
        {
            cout << "Name : " << name << endl;
        }
    }
};
int main()
{
    int n, y, m, d;
    cout << "enter how many data you want : ";
    cin >> n;
    Person p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].input();
    }
    cout << "enter the date of birth you want to search (YY MM DD format):";
    cin >> y >> m >> d;
    for (int i = 0; i < n; i++)
    {
        p[i].match(y, m, d);
    }
}