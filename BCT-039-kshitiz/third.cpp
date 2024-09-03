#include<iostream>
using namespace std;
class library
{
    public:
    string title,author;
    void addbook()
    {
        cout<<"Enter the name of name and author of the book"<<endl;
        cin.ignore();
        getline(cin,title);
        cin.ignore();
        getline(cin,author);
    }
    void issbook()
    {
        cout<<"Enter the name and author of the book"<<endl;
        cin.ignore();
        getline(cin,title);
        cin.ignore();
        getline(cin,author);
    }
    void retbook()
    {
        cout<<"Enter the name and author of book"<<endl;
        cin.ignore();
        getline(cin,title);
        cin.ignore();
        getline(cin,author);
    }
};
int main()
{
    int n,num,i,count=0,j;
    static int noc=0;
    static library lib[1000];
    library iss[1000];
    library ret[1000];
    while(1)
    {
        cout<<"Operation on library:"<<endl;
        cout<<"1. Add new books"<<endl<<"2. Issue books"<<endl<<"3.Return books"<<endl<<"4.No of copiees"<<endl<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
            cout<<"Enter the number of books you want to add"<<endl;
            cin>>num;
            for(i=0;i<num;i++)
            {
            int j=1;
            lib[i].addbook();
            noc=noc+1;
            }
            cout<<" Book Added  "<<endl<<endl;
            break;

            //case 2
            case 2:
            if(noc==0)
            {
                cout<<"Add the book first"<<endl<<endl;
            }
            else
            {
            cout<<"Enter the number of books you want to issue"<<endl;
            cin>>num;
            for(i=0;i<num;i++)
            {
            lib[i].issbook();
            for(i=0;i<noc;i++)
            {
                if(j==1)
                {
                if((lib[i].title==(lib[i+1].title))&&(lib[i].author)==(lib[i+1].author))
                {
                    noc=noc-1;
                }
                else{
                    cout<<"Title and Author name didnot matched."<<endl;
                }
                }
                else{
                    noc=noc-1;
                }
            }
            cout<<"Book Issued  "<<endl<<endl;
            }
            break;

            //case 3:
            case 3:
            cout<<"Enter the number of books you want to return"<<endl;
            cin>>num;
            for(i=0;i<num;i++)
            {
                lib[i].retbook();
                if(j==1){
                for(i=0;i<noc;i++)
                {
                if((lib[i].title==(lib[i+1].title))&&(lib[i].author)==(lib[i+1].author))
                {
                    noc=noc+1;
                }
                else{
                    cout<<"Title and Author name didnot matched."<<endl;
                }
                }
                }
                else{
                    noc=noc+1;
                }
            }
            cout<<" Book Returned  "<<endl<<endl;
            break;

            //case 4:
            case 4:
            cout<<"Number of books is:"<<noc<<endl<<endl;
            break;
            default:
            cout<<"Your choice is invalid."<<endl;
        }
    }
    }
    return 0;
}