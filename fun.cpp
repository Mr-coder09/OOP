
#include<iostream>
using namespace std;  //i create function template for selection sort
template<class T>   //declaring template ,template is a keyword,class/typename is also keyword,T is template variable,tempary place ho
class sort   //create class sort
{
        //data_type arrayname[size];
        T a[50];   //create arry ,type of array is T and name is a
        int n;   // size of that array
    public:
        void accept()
        {
            cout<<"\n Enter no. of elements in an array";
            cin>>n;
            cout<<"\n Enter elements";
            for(int i=0;i<n;i++)
            {
                cin>>a[i];  //passing the elements into the a array
            }
        }
        void selection_sort()
        {
            T temp;//declaring temp variable of type T,if we sort the integer array the datatype of T will integet ....float
                for(int i=0;i<n-1;i++)
                {
                    int min=i;//the smallest element is at 0th position ,if not swaping occurs
                    for(int j=i+1;j<n;j++)
                    {
                        if(a[min]>a[j])
                        {
                            min=j;
                        }
                    }
                    temp=a[min];   //temp is used for swaping
                    a[min]=a[i];
                    a[i]=temp;
                }
        }
        void display()
        {
            cout<<"The Sorted Array Is:"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" "<<endl;
            }
        }
};
int main()
{
    sort <int> s1;  //s1 for integer.call function template with integer value.it sort integer
    sort <float> s2;  //s2 for float.call function template with float value
    int ch;
    do
    {
        cout<<"---------------MENU---------"<<endl;
        cout<<"1. Enter Int Data:"<<endl;
        cout<<"2. Enter float data:"<<endl;
        cout<<"3. Exit:"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                s1.accept();
                s1.selection_sort();
                s1.display();
                break;
            case 2:
                s2.accept();
                s2.selection_sort();
                s2.display();
                break;
            case 3:
                cout<<"Exit";
                exit(0);
        }
    }
    while (ch!=4);
    return 0;
}
//we creat generic function which work for both the type int and float