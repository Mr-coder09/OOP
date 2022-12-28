
#include <iostream>
#include <string>
using namespace std;
 
class publication      //create class publication 
    {
        string title;   //declare two variable 
        float price;
        public:     
                void get_data()   //in public section i have add getdata and display function getdata for add info and ...
                {                //getline for spaces inside the title of the publication
                    cout<<"Enter Title : ";
                    cin.ignore();
                    getline(cin,title);
                    cout<<"Enter Price : ";
                    cin>>price;
                }
                void display()
                {
                    cout<<"Tile - "<<title<<endl;
                    cout<<"Price - "<<price<<endl;
                }
};
  
class book:public publication   //use inheritance,i create class book which is inherited from class publication publicaly
{        //private members are not accesible and private members are variables that is title and price
    int page_count;   //in private section declare    declare private variable page count
    public:
        void get_data()   //for add the data
        {
            try
            {
                publication::get_data();   //here i call getdata function of base class,title and price already accepted so i am asking 
                cout<<"Enter Page Count : ";//for page count
                cin>>page_count;
                if (page_count <= 0 ) //invalid 
                throw page_count;
            }
            catch(...)  //any type of exception can catch
            {
                cout<<"Invalid page count"<<endl;
                page_count = 0;
            }
            cout<<"\n\n";
        }
        void display()
        {
            publication::display();   //here i call display function of the base class
            cout<<"Page count -"<<page_count<<endl;  //display title ,price and pagecount
            cout<<"\n\n";
        }
};
 
class tape:public publication
{
    float play_time;
    public:
    void get_data()
    {
        try
        {
            publication::get_data();
            cout<<"Enter Play time : ";
            cin>>play_time;
            if (play_time <= 0 )
            throw play_time;
        }
        catch(...)
        {
            cout<<"Invalid Playtime"<<endl;
            play_time = 0;
        }
        cout<<"\n\n";
    }
    void display()
    {
        publication::display();
        cout<<"Play Time -"<<play_time<<endl;
        cout<<"\n\n";
    }
};
 
int main()
{
    book b[10];  //b is array of objects and object is book
    tape t[10];  //all book info in b and all tape info in t
    int ch, bcount = 0,tcount = 0;  //declare b and t as 0
    do
    {
        cout<<"====Publication Details====\n"
            <<"1.Add Book Details\n"
            <<"2.Add Tape Details\n"
            <<"3.Display Book Details\n"
            <<"4.Display Tape Details\n"
            <<"5.Exit\n\n";
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1://for add info in book database
                b[bcount].get_data();  //bcount represents the book count ,initily it is 0.as i add 1 book it will increment 
                bcount++;
                break;
            case 2://tape
                t[tcount].get_data();
                tcount++;
                break;
            case 3:
                for (int i = 0; i < bcount; i++)
                {
                b[i].display();//display from start to end ,if 5 display 4 records
                }
                break;
            case 4:
                for (int i = 0; i < tcount; i++)
                {
                t[i].display();
                }
                break;
            case 5:
                cout<<"Exit Statment \n";
                exit(0);
        }
    }while(ch != 0);
    return 0;
 }
 //create class publication and data members as title and price
//derive two classes from class publication as class book and tape
//instantiate bok and tape class to accept and display the information
//in the class publication title and price are data members and getdata()and display are member function
//in book pagecount and in tape playtime
