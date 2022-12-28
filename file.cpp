
#include<iostream>  //headerfile
#include<fstream>
#include<string.h>
using namespace std;
class student  //class student
{
    private:
        string name;  //we have to store the info in the file so i declare 3 variables
        int rollno;
         int marks;
    public:  //in the class 2 functions
        char ch;
        void getdata()
        {
            ofstream o2;  //declaring object of the class,create object o2 of type ofstream,it allows to create file stream
            o2.open("gayatri.txt",ios::app);//opening file in append mode so information can add at the end
            if(o2.fail())
            {
                cout<<"problem in file creation";
            }
            else//if file open successfully so we can add data intoit
            {
                cout<<"Enter name of student:"<<endl;
                cin>>name;
                cout<<"Enter roll no.:"<<endl;
                cin>>rollno;
                cout<<"Enter marks:"<<endl;
                cin>>marks;
                o2<<rollno;
                o2<<" ";  //information can copy to file
                o2<<name;
                o2<<" ";
                o2<<marks;
                o2<<"\n";  //new line
                o2.close();//close the file
            }
        }
        void display()
        {
            ifstream i1;    //here we are trying to read the record whatever record is in the file
            i1.open("gayatri.txt");  //open the file
            if(i1.fail())
            {
                cout<<"Error in reading file";
            }
            else
            {
                while(true)   
                {
                    i1.get(ch);
                    if(i1.eof())  //end of the file ,read till end of the file
                    break;
                    cout<<ch;
                }
                
            }
        }
};
int main()
{
    student s1;   //s1 is the object of student class
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
            case 1: // for add info in the student class
                s1.getdata();
                break;
            case 2://display 
                s1.display();
                break;
            case 3:
                exit(0);
        }
    }
    while(ch!=3);
    return 0;
}
