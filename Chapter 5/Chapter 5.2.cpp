#include <iostream>

//#define START1
#define START2


using namespace std;






#ifdef START1

#include <cstring>
//ShallowCopyError.cpp
class Person
{
	private:
		char* name;
		int age;
		
	public:		
		Person(char * myname, int myage)
		{
			int len = strlen(myname)+1;
			name = new char[len];
			strcpy(name,myname);
			age =myage;
		}
		
		Person(const Person& copy) :age(copy.age)
		{
			name = new char [strlen(copy.name)+1];
			strcpy(name, copy.name);
		}
		
		void ShowPersonInfo() const
		{
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl;
		}
		
		~Person()
		{
			delete []name;
			cout<<"called destructor!"<<endl;
		}
};

int main(void)
{
	Person man1("Lee dong woo",29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	return 0;
}

#endif /* START1 */





#ifdef START2

//p226 Question 5-1
#include <cstring>


namespace COMP_POS
{
	enum
	{
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
	
	void ShowPositionInfo(int pos)
	{
		switch(pos)
		{
			case CLERK:
				cout<<"사원"<<endl;
			
			case SENIOR:
				cout<<"주임"<<endl;
			
			case ASSIST:
				cout<<"대리"<<endl;
			
			case MANAGER:
				cout<<"과장"<<endl;
		}
	}
}

class NameCard
{
	private:
		char *name;
		char *company;
		char* phone;
		int position;
			
	public:
		NameCard(char *_name, char * _company, char * _phone, int pos) : position(pos)
		{
			name = new char[strlen(_name)+1];
			company = new char[strlen(_company)+1];
			phone = new char[strlen(_phone)+1];
			strcpy(name, _name);	
			strcpy(company, _company);
			strcpy(phone, _phone);
		
		}
		
		NameCard(const NameCard& ref) :position(ref.position)
		{
			name = new char [strlen(ref.name)+1];
			company = new char[strlen(ref.company)+1];
			phone = new char[strlen(ref.phone)+1];
			strcpy(name, ref.name);
			strcpy(company, ref.company);
			strcpy(phone, ref.phone);
		}
		
		void ShowNameCardInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"회사: "<<company<<endl;
			cout<<"전화번호: "<<phone<<endl;
			cout<<"직급: "; COMP_POS::ShowPositionInfo(position);
			cout<<endl;
		}
		
		
		~NameCard()
		{
			delete []name;
			delete []company;
			delete []phone;
			
			cout<<"called destructor!"<<endl;
		}
	
};


int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	
	return 0; 
}

#endif /* START2 */