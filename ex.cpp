
#include <iostream>
#include <string>
using namespace std;
 
class publication
    {
        string title;
        float price;
        public:
                void get_data()
                {
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
  
class book:public publication
{
    int page_count;
    public:
        void get_data()
        {
            try
            {
                publication::get_data();
                cout<<"Enter Page Count : ";
                cin>>page_count;
                if (page_count <= 0 )
                throw page_count;
            }
            catch(...)
            {
                cout<<"Invalid page count"<<endl;
                page_count = 0;
            }
            cout<<"\n\n";
        }
        void display()
        {
            publication::display();
            cout<<"Page count -"<<page_count<<endl;
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
    book b[10];
    tape t[10];
    int ch, bcount = 0,tcount = 0;
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
            case 1:
                b[bcount].get_data();
                bcount++;
                break;
            case 2:
                t[tcount].get_data();
                tcount++;
                break;
            case 3:
                for (int i = 0; i < bcount; i++)
                {
                b[i].display();
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
