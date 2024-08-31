// Define a class Library with bookTitle , author, and numberOfCopies as data 
// members.Implement methods to add new books, issue books,and return books.Ensure
// that the number of copies is appropriately updated for each operation.


#include <iostream>
using namespace std;

class Library{
    char bookTitle[50];
    char author[40];
     int numberofcopies=0  ;

    public:

    void getinput(){
        cout << "Enter book title: ";
            cin.getline(bookTitle, 100);
            cout << "Enter author name: ";
            cin.getline(author, 30);
            cout << "Enter number of copies: ";
            cin >> numberofcopies;

    }

    void getoutput(){
        cout<<"The details:"<<endl;
        cout<<"Book Title:"<<bookTitle<<endl;
         cout<<"Author:"<<author<<endl;
          cout<<"Number of copies:"<<numberofcopies<<endl;

    }

    void addnewbook(int n){
        numberofcopies+=n;
        cout<<n<<" Books added"<<endl;
     }

     void issuebook(){
        if(numberofcopies == 0){
                cout << "No book available" << endl;
            } else {
                numberofcopies--;
                cout << "Book issued successfully\n";
            }
        }

     
     void returnbook(){
        numberofcopies ++;
        cout<<"Book returned successfuly."<<endl;



     }




};
int main(){
   
    Library l;
    l.getinput();

    int choice, n;

    while(true){
        system("cls");
        cout << "Welcome to the library\n1.Show Book Details\n2.Add Books\n3.Issue Book\n4.Return Book\n5.Exit\n\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << endl << endl;
                l.getoutput();
                break;
            case 2:
                cout << "Enter the number of books: ";
                cin >> n;
                l.addnewbook(n);
                break;
            case 3:
                l.issuebook();
                break;
            case 4:
                l.returnbook();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid Choice...";
        }
        cout << "\nPress enter to continue:";
        cin.ignore();
        cin.get();
    }
}