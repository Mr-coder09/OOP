
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
    private:
        string name;
        int rollno;
         int marks;
    public:
        char ch;
        void getdata()
        {
            ofstream o2;
            o2.open("gayatri.txt",ios::app);
            if(o2.fail())
            {
                cout<<"problem in file creation";
            }
            else
            {
                cout<<"Enter name of student:"<<endl;
                cin>>name;
                cout<<"Enter roll no.:"<<endl;
                cin>>rollno;
                cout<<"Enter marks:"<<endl;
                cin>>marks;
                o2<<rollno;
                o2<<" ";
                o2<<name;
                o2<<" ";
                o2<<marks;
                o2<<"\n";
                o2.close();
            }
        }
        void display()
        {
            ifstream i1;
            i1.open("gayatri.txt");
            if(i1.fail())
            {
                cout<<"Error in reading file";
            }
            else
            {
                while(true)   
                {
                    i1.get(ch);
                    if(i1.eof())
                    break;
                    cout<<ch;
                }
                //;
            }
        }
};
int main()
{
    student s1;
    int ch;
    do
    {
        cout<<"\n*****************************STUDENT  DATABASE*****************";
        cout<<"\n MENU";
        cout<<"\n 1. Add Student Record";
        cout<<"\n 2. Display Student Record";
        cout<<"\n 3. Exit";
        cout<<"\n Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                s1.getdata();
                break;
            case 2:
                s1.display();
                break;
            case 3:
                exit(0);
        }
    }
    while(ch!=3);
    return 0;
}
