
#include<iostream>
using namespace std;
 
class Complex
{
    int x; 
    int y;
    public:
        Complex()
        {
            x=y=0; 
        }
        Complex operator +(Complex);
        Complex operator *(Complex);
        friend istream & operator >>(istream &input,Complex &c)
        {
            cout<<"\n Enter real part of complex no: ";
            input>>c.x;
            cout<<"\n Enter imaginary part of complex no: ";
            input>>c.y;
            return input;
        }
        friend ostream & operator <<(ostream &output,Complex &c)
            {
                output<<c.x<<"+"<<c.y<<"i"<<endl;
                return output;
            }
};
 
Complex Complex::operator + (Complex c)
{
    Complex temp;
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
    Complex c1,c2,c3,c4;
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
