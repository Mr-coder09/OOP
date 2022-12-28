
#include <iostream>    //header file
#include <algorithm> //generic header file,inbuilt function for searching and sorting
#include <vector> //standard template library

using namespace std;
class Item  //class item
{
  public: char name[10]; //create array to store the information
  int quantity;//declare variables
  int cost;
  int code;

    
	    bool operator==(const Item& i1) //==operator overload for searching the record
    {
        if(code==i1.code) //here i am comparing to item codes ,so it return 
        return 1;//if true
        return 0;//if false
    }
 bool operator<(const Item& i1)
{
    if(cost<i1.cost)  //here i comparing cost of item
    return 1;
    return 0;
}

};

vector<Item> o1;//create vector and the name of the vector is item,in this vector infois adding
void print(Item &i1);   //these are the functions
void display();  // for each function we write separate code
void insert();
void search();
void dlt();

bool compare(const Item &i1, const Item &i2) 
{
   
   return i1.cost< i2.cost;      
}

int main()
{
int ch;
do
{       
    cout<<"\n***** Menu *****";
    cout<<"\n1.Insert";
    cout<<"\n2.Display";
    cout<<"\n3.Search";
    cout<<"\n4.Sort";
    cout<<"\n5.Delete";
    cout<<"\n6.Exit";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:  insert();
          break;
    case 2:  display();
          break;
    case 3:  search();
          break;     
    case 4:  sort(o1.begin(),o1.end(),compare);
      cout<<"\n\n Sorted on Cost";
      display();
          break; 
    case 5:  dlt();
          break;
    case 6:  exit(0);
    }
  
}while(ch!=7);

  return 0;
}

void insert()
{
    Item i1;
    cout<<"\nEnter Item Name:";
    cin>>i1.name;
    cout<<"\nEnter Item Quantity:";
    cin>>i1.quantity;
    cout<<"\nEnter Item Cost:";
    cin>>i1.cost;
    cout<<"\nEnter Item Code:";
    cin>>i1.code;
    o1.push_back(i1);   //add element to end of the function,this is the inbuilt function
}

void display()
{
 for_each(o1.begin(),o1.end(),print); //for each is function which execute from start to end
}
void print(Item &i1)
{
  cout<<"\n";
  cout<<"\nItem Name:"<<i1.name;
  cout<<"\nItem Quantity:"<<i1.quantity;
  cout<<"\nItem Cost:"<<i1.cost;
  cout<<"\nItem Code:"<<i1.code;
}
void search()
{
 vector<Item>::iterator p;
 Item i1;
 cout<<"\nEnter Item Code to search:";
 cin>>i1.code;
 p=find(o1.begin(),o1.end(),i1);  //finf is also inbuilt function
  if(p==o1.end())
   cout<<"\nNot found.";
  else
 {
   cout<<"\nFound.";    
 }
}
void dlt()
{
  vector<Item>::iterator p;
 Item i1;
 cout<<"\nEnter Item Code to delete:";
 cin>>i1.code;
 p=find(o1.begin(),o1.end(),i1);
  if(p==o1.end())
   cout<<"\nNot found.";
  else
 {
   o1.erase(p);
   cout<<"\nDeleted.";
 }

}
