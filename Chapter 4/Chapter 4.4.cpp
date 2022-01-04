#include <iostream>
#include <cstring>

//#define START1
//#define START2
//#define START3
//#define START4
#define START5
#define START6

using namespace std;

#ifdef START1

//ObjArr.cpp
class Person
{
	private:
		char *name;
		int age;
	
	public:
		Person(char *myname, int myage)
		{
			int len = strlen(myname)+1;
			name = new char[len];
			strcpy(name, myname);
			age = myage;
		}
		
		Person()
		{
			name = NULL;
			age = 0;
			cout<<"called Person"<<endl;
		}
		
		void SetPersonInfo(char *myname, int myage)
		{
			name = myname;
			age = myage;
		}	
		
		void ShowPersonInfo() const
		{
			cout<<"이름: "<<name<<", ";
			cout<<"나이: "<<age<<endl;
		
		}
	
		~Person()
		{
			delete []name;
			cout<<"called destructor"<<endl;
		}
	 
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char * strptr;
	int age;
	int len;
	
	for(int i=0; i<3; i++)
	{
		cout<<"이름: ";
		cin>>namestr;
		cout<<"나이: ";
		cin>>age;
		len=strlen(namestr)+1;
		strptr = new char [len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
		
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	
	
	return 0;
}
#endif /* START1 */



#ifdef START2

//ObjPtrArr.cpp
class Person
{
	private:
		char *name;
		int age;
	
	public:
		Person(char *myname, int myage)
		{
			int len = strlen(myname)+1;
			name = new char[len];
			strcpy(name, myname);
			age = myage;
		}
		
		Person()
		{
			name = NULL;
			age = 0;
			cout<<"called Person"<<endl;
		}
		
		void SetPersonInfo(char *myname, int myage)
		{
			name = myname;
			age = myage;
		}	
		
		void ShowPersonInfo() const
		{
			cout<<"이름: "<<name<<", ";
			cout<<"나이: "<<age<<endl;
		
		}
	
		~Person()
		{
			delete []name;
			cout<<"called destructor"<<endl;
		}
	 
};

int main(void)
{
	Person * parr[3];
	char namestr[100];
	int age;
	
	for(int i=0; i<3; i++)
	{
		cout<<"이름: ";
		cin>>namestr;
		cout<<"나이: ";
		cin>>age;
		parr[i]=new Person(namestr, age);
		
	}
	
	parr[0]-> ShowPersonInfo();
	parr[1]-> ShowPersonInfo();
	parr[2]-> ShowPersonInfo();
	
	delete parr[0];
	delete parr[1];
	delete parr[2];
	
	return 0;
	
}
#endif /*  */


#ifdef START3

//PointerThis.cpp
class SoSimple
{
	private:
		int num;
	
	public:
		SoSimple(int n) : num(n)
		{
			cout<<"num = "<<num<<", ";
			cout<<"address = "<<this<<endl;
		}	
		
		void ShowsSimpleData()
		{
			cout<<num<<endl;
		}
		
		SoSimple *GetThisPointer()
		{
			return this;
		}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple *ptr1= sim1.GetThisPointer();
	cout<<ptr1<<", ";
	ptr1->ShowsSimpleData();
	
	SoSimple sim2(200);
	SoSimple *ptr2= sim2.GetThisPointer();
	cout<<ptr2<<", ";
	ptr2->ShowsSimpleData();
	
	return 0;
}
#endif /* START3 */





#ifdef START4

//UsefulThisPtr.cpp
class TwoNumber
{
	private:
		int num1;
		int num2;
	
	public:
		TwoNumber(int num1, int num2)
		{
			this->num1=num1;
			this->num2=num2;
		}
		/*
		TwoNumber(int num1, int num2) : num1(num1), num2(num2)
		{
			//empty
		}
		*/
		
		void ShowTwoNumber()
		{
			cout<<this->num1<<endl;
			cout<<this->num2<<endl;
		}
				
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	
	return 0;
}
#endif /* START4 */





#ifdef START5

//SelfRef.cpp
class SelfRef
{
	private:
		int num;
	
	public:
		SelfRef(int n) :num(n)
		{
			cout<<"객체생성"<<endl;
		}
		
		SelfRef& Adder(int n)
		{
			num+= n;
			return *this;
		}
		
		SelfRef& ShowTwoNumber()
		{
			cout<<num<<endl;
			return *this;
		}
		
		
};


int main (void)
{
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);
	
	obj.ShowTwoNumber();
	ref.ShowTwoNumber();
	
	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	
	return 0;
}
#endif /* START5 */
