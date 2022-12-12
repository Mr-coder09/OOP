
#include<iostream>
using namespace std;
template<class T>
class sort
{
        //data_type arrayname[size];
        T a[50];
        int n;
    public:
        void accept()
        {
            cout<<"\n Enter no. of elements in an array";
            cin>>n;
            cout<<"\n Enter elements";
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        }
        void selection_sort()
        {
            T temp;
                for(int i=0;i<n-1;i++)
                {
                    int min=i;
                    for(int j=i+1;j<n;j++)
                    {
                        if(a[min]>a[j])
                        {
                            min=j;
                        }
                    }
                    temp=a[min];
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
    sort <int> s1;
    sort <float> s2;
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
