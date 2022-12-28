#include<iostream>
#include<string>
using namespace std;

class student //class
{
	private:
	string name,cls,dob,bld_grp,add,lic_no;
	int *roll_no,div,mob_no;
	public:
	friend class teacher;
		student() //default constructor
		{
			roll_no=new int;
			name,cls,dob,bld_grp,add,lic_no=" ";
			roll_no,div,mob_no=0;

		}
		student(student &st) //copy constructor
		{
			this->roll_no= st.roll_no;
			this->name= st.name;
			this->cls= st.cls;
			this->dob= st.dob;
			this->bld_grp= st.bld_grp;
			this->add= st.add;
			this->lic_no= st.lic_no;
			this->div= st.div;
			this->mob_no= st.mob_no;
		}

		~student() //destructor
		{

			delete roll_no;

		}

		inline static void header_info()
		{
			cout<<"\n *************************STUDENT INFORMATION***************************";
			cout<<"\nname\t\tcls\tdob\tbld_grp\tadd\t\tlic_no\troll_no\tdiv\tmob_no";
		}

		void get_data()
		{
			cout<<"Enter your roll_no: ";
			cin>>*roll_no;
			cout<<"Enter your name: ";
			cin>>name;
			cout<<"Enter your cls: ";
			cin>>cls;
			cout<<"Enter your dob: ";
			cin>>dob;
			cout<<"Enter your bld_grp: ";
			cin>>bld_grp;
			cout<<"Enter your add: ";
			cin>>add;
			cout<<"Enter your lic_no: ";
			cin>>lic_no;
			cout<<"Enter your div: ";
			cin>>div;
			cout<<"Enter your mob_no: ";
			cin>>mob_no;
		}

		void display()
		{
			cout<<"\n"<<name
			<<"\t"<<*roll_no
			<<"\t"<<div<<"\t"
			<<cls<<"\t"
			<<dob<<"\t"
			<<mob_no<<"\t"
			<<bld_grp<<"\t"
            <<add<<"\t"
            <<lic_no;
		}

};

class teacher
{
	int id;
	public:
		teacher()
		{
			id=0;
		}
		void display_t(student &obj, int t_d)
		{
			try
			{
				if(obj.div==t_d)
					obj.display();
				else 
				throw (obj.div);
			}
			catch(int x)
			{
			cout<<"Student division & teacher division is mismatched";
			}
		}
};                                                                                        



int main()
{
	student s[2];
	teacher t;
	int ch,count=0;
	do 
	{ 
	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _MENU_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;;
	cout<<"1.Add Student Data"<<endl;
	cout<<"2.Display Student Data"<<endl;
	cout<<"3.Copy constructor"<<endl;
	cout<<"4.Division wise display"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<endl;
	cout<<"Enter your choice";
	cin>>ch;
	
	switch (ch)
	{
		case 1:
			s[count].get_data(); //s[0].get data;
			count++;
			break;
		case 2:
			student::header_info();
			for (int i=0;i<count;i++)
			{	
				s[i].display();
			}
			break;
		case 3:
			{
			cout<<"This is copy constructor"<<endl;
			student s1;
			s1.get_data();
			student s2(s1);
			s2.display();
			}
			break;
		case 4:
			int t_div;
			cout<<"Enter Division";
			cin>>t_div;
			for(int i=0;i<count;i++)
			{
			t.display_t(s[i],t_div);
			}
			break;
		case 5:
			exit(0);
	}
	} while(ch!= 5);
 
	return 0;
}



