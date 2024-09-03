#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
class Library
{
    vector<string> Title;
    vector<string> Author;
    vector<int> numberofcopies;

public:
    void viewbook()
    {
        int i = 0;
        for (string &title : Title) 
        {
            cout << "Title : " << title << endl;
            cout << "Author : " << Author[i] << endl;
            cout << "Number of copies : " << numberofcopies[i] << endl
                 << endl;
            i++;
        }
    }
    void newbook()
    {
        string input;
        int copies;
        cin.ignore();
        cout << "Enter the name of the book : " << endl;
        getline(cin, input);
        for (string &title : Title)
        {
            if (input == title)
            {
                cout << "Book is already there.";
                return;
            }
        }
        Title.push_back(input);
        cout << "Enter the name of the author : " << endl;
        getline(cin, input);
        Author.push_back(input);
        cout << "Enter the number of copies : " << endl;
        cin >> copies;
        numberofcopies.push_back(copies);
        cin.ignore();
    }
    void issuebook()
    {
        string input;
        cin.ignore();
        cout << "Title of the book you want to take : ";
        getline(cin, input);
        for (size_t i = 0; i < Title.size(); i++) //size_t vaneko xai unsigned
        {
            if (input == Title[i])
            {
                if (numberofcopies[i] > 0)
                {
                    cout << "Book issued.";
                    numberofcopies[i]--;
                }
                else
                {
                    cout << "Book is not available.";
                }
            }
            else
            {
                cout << "Book not found." << endl;
                return;
            }
        }
    }
    void returnbook()
    {
        string input;
        cin.ignore();
        cout << "Title of the book you want to return : ";
        getline(cin, input);
        for (size_t i =0; i<Title.size();i++)
        {
            if (input == Title[i])
            {
                cout << "Book returned.";
                numberofcopies[i]++;
            }
            else
            {
                cout << "Book not found." << endl;
                return;
            }
        }
    }
};
int main()
{
    int n;
    Library l;
    while (true)
    {
        cout << "\n1. Add New Book.\n2. Issue Book\n3. Return Book\n4. Available Books\n5. Exit\n";
        cout << "\nEnter your choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            l.newbook();
            break;
        case 2:
            l.issuebook();
            break;
        case 3:
            l.returnbook();
            break;
        case 4:
            cout << "\nAvailable Books : " << endl
                 << endl;
            l.viewbook();
            break;
        case 5:
            exit(0);
        default:
            "Invalid Input ";
            break;
        }
    }
}