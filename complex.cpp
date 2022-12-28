
#include<iostream>       //headerfile which is required in c++
using namespace std;     
 
class Complex          //create class
{
    int x;            //declare two variables for real part x,and for img part y
    int y;
    public:        //after declaring data members of complex numbers
        Complex()     //create constructor same name as class name ,no parameteres associated with default constructor 
        {              //which initialise the value of data member 
            x=y=0; 
        }
        Complex operator +(Complex);   //these two methods define outside the class and declare inside the class 
        Complex operator *(Complex);   //but insertion and extraction we write inside the class only
        friend istream & operator >>(istream &input,Complex &c)  //in extraction we are passing object of istream as inputand comp no.
        {              //here we are passing address of that stream
            cout<<"\n Enter real part of complex no: ";
            input>>c.x;
            cout<<"\n Enter imaginary part of complex no: ";
            input>>c.y;
            return input;
        }
        friend ostream & operator <<(ostream &output,Complex &c) //for insertion we are displaying tht comp no as output
            {
                output<<c.x<<"+"<<c.y<<"i"<<endl;
                return output;
            }
};
 
Complex Complex::operator + (Complex c)   //for + operator declaration i write outside the class
{
    Complex temp;   //for addition i create temperary complex number and do addition
    temp.x=x+c.x;
    temp.y=y+c.y;
    return temp;
}
Complex Complex:: operator * (Complex c)
{
    Complex temp;
    temp.x=(x*c.x)-(y*c.y);
    temp.y=(x*c.y)+(y*c.x);
    return temp;
}
 
int main()
{
    Complex c1,c2,c3,c4;      //in main i create 4 objects in which 2 numbers and c3 for add and c4 for mul
    int ch;
do
{
    cout<<"--------------MENU-------------";
    cout<<"\n 1.Default constructor";
    cout<<"\n 2.Add complex numbers";
    cout<<"\n 3.Display complex numbers";
    cout<<"\n 4.Addition of complex numbers";
    cout<<"\n 5.Multiplication of complex numbers";
    cout<<"\n 6.Exit";
    cout<<"\n Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        cout<<"\n Default constructor: ";
        cout<<c1;
        break;
    case 2:
        cout<<"\n ===Enter first no=== ";
        cin>>c1;
        cout<<"\n ===Enter second no===";
        cin>>c2;
        break;
    case 3:
        cout<<"\n 1st complex no: ";
        cout<<c1;
        cout<<"\n 2nd complex no: ";
        cout<<c2;
        break;
    case 4:
        c3=c1+c2;
        cout<<"\n Addition of complex no is: ";
        cout<<c3;
        break;
    case 5:
        c4=c1*c2;
        cout<<"\n Multiplication of complex no is: ";
        cout<<c4;
        break;
    case 6:
        cout<<"Exited............";
        exit(0);
    }
}while(ch!=6);
    return 0;
}
