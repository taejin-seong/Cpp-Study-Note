#include <iostream>
#include <cstring>

//#define START1
//#define START2
//#define START3
//#define START4
//#define START5
#define START6
using namespace std;





#ifdef START1

//UnivStudentinheri.cpp
class Person
{
	private:
		int age;
		char name[50];
	
	public:
		Person(int myage, char* myname) : age(myage)
		{
			strcpy(name, myname);
		}
		
		void WhatYourName() const
		{
			cout<<"My name is "<<name<<endl;
		}
		
		void HowOldAreYou() const
		{
			cout<<"I'm "<<age<<" years old"<<endl;
		}
};

class UnivStudent : public Person
{
	private:
		char major[50];
		
	public:
		UnivStudent(char* myname, int myage, char* mymajor) : Person(myage, myname)
		{
			strcpy(major, mymajor);
		}
		
		void WhoAreYou() const
		{
			WhatYourName();
			HowOldAreYou();
			cout<<"My major is "<<major<<endl;
		}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	
	UnivStudent ustd2("Yoon", 21, "Electronic eng");
	ustd2.WhoAreYou();
	
	return 0;
}
#endif /* START1 */




#ifdef START2

//DerivCreOrder.cpp
//기초 클래스 
class SoBase  
{
	private:
		int baseNum;
	
	public:
		SoBase() : baseNum(20)
		{
			cout<<"SoBase()"<<endl;
		}
		
		SoBase(int n) : baseNum(n)
		{
			cout<<"SoBase(int n)"<<endl;
		}
		
		void ShowBaseData()
		{
			cout<<baseNum<<endl;
		}
};

//유도 클래스 
class SoDerived : public SoBase 
{
	private:
		int derivNum;
		
	public:
		SoDerived() : derivNum(30)
		{
			cout<<"SoDerived()"<<endl;
		}
		
		SoDerived(int n) : derivNum(n)
		{
			cout<<"SoDerived(int n)"<<endl;
		}
		
		SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
		{
			cout<<"SoDerived(int n1, int n2)"<<endl;
		}
		
		void ShowDerivData()
		{
			ShowBaseData();
			cout<<derivNum<<endl;
		}
};

int main(void)
{
	cout<<"case1......"<<endl;
	
	SoDerived dr1;
	dr1.ShowDerivData();
	
	cout<<"------------"<<endl;
	cout<<"case2......"<<endl;
	
	SoDerived dr2(12);
	dr2.ShowDerivData();
	
	cout<<"------------"<<endl;
	cout<<"case3......"<<endl;
	
	SoDerived dr3(23,24);
	dr3.ShowDerivData();
	
	return 0;
}
#endif /* START2 */




#ifdef START3

//DerivDestOrder.cpp
class SoBase
{
	private:
		int baseNum;
	
	public:
		SoBase(int n) : baseNum(n)
		{
			cout<<"SoBase() : "<<baseNum<<endl;
		}
		
		~SoBase()
		{
			cout<<"~SoBase() : "<<baseNum<<endl;
		}
};

class SoDerived : public SoBase
{
	private:
		int derivNum;
		
	public:
		SoDerived(int n) : SoBase(n), derivNum(n)
		{
			cout<<"SoDerived() : "<<derivNum<<endl;
		}
		
		~SoDerived()
		{
			cout<<"~SoDerived() : "<<derivNum<<endl;
		}
		
};

int main(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);
	
	return 0;
}
#endif /* START3 */




#ifdef START4

//DestModel.cpp
class Person
{
	private:
		char* name;
	
	public:
		Person(char* myname)
		{
			name = new char[strlen(myname)+1];
			strcpy(name, myname);
		}
		
		~Person()
		{
			delete []name;
		}
		
		void WhatYourName() const
		{
			cout<<"My name is "<<name<<endl;
		}
};

class UnivStudent : public Person
{
	private:
		char* major;
		
	public:
		UnivStudent(char* myname, char* mymajor) : Person(myname)
		{
			major = new char[strlen(mymajor)+1];
			strcpy(major, mymajor);
		}
		
		~UnivStudent()
		{
			delete []major;
		}
		
		void WhoAreYou() const
		{
			WhatYourName();
			cout<<"My major is "<<major<<endl<<endl;
		}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	
	return 0;
}
#endif /* START4 */




#ifdef START5

//p294 Question 7-1 NO.1
class Car
{
	private:
		int gasolineGauge;
		
	public:
		Car(int gas) : gasolineGauge(gas) 
		{
		
		}
		
		int GetGasGauge()
		{
			return gasolineGauge;			
		}
};

class HybridCar : public Car
{
	private:
		int electricGauge;
	
	public:
		HybridCar(int gas, int electric) : Car(gas), electricGauge(electric) 
		{
		
		}
	
		int GetElecGauge()
		{
			return electricGauge;
		}
};

class HybridWaterCar : public HybridCar
{
	private:
		int waterGauge;
		
	public:
		HybridWaterCar(int gas, int electric, int water) : HybridCar(gas, electric), waterGauge(water) 
		 {
		 
		 }
		
		void ShowCurrentGauge()
		{
			cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
			cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
			cout<<"잔여 워터량: "<<waterGauge<<endl;
		}
};

int main(void)
{
	HybridWaterCar hywcar(10, 20, 30);
	hywcar.ShowCurrentGauge();
	
	return 0;
}
#endif /* START5 */





#ifdef START6

//p295 Question 7-1 NO.2
class MyFriendInfo
{
	private:
		char* name;
		int age;
	
	public:
		MyFriendInfo(char * fname, int fage) : age(fage)
		{
			name = new char [strlen(fname)+1];
			strcpy(name, fname);
		}
		
		void ShowMyFriendInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl;
		}	
		
		~MyFriendInfo()
		{
			delete []name;
			
		}
};

class MyFriendDetailInfo : public MyFriendInfo
{
	private:
		char* addr;
		char* phone;
		
	public:
		MyFriendDetailInfo(char* fname, int fage, char* faddr, char* fphone) : MyFriendInfo(fname, fage)
		{
			 addr = new char [strlen(faddr)+1];
			phone = new char [strlen(fphone)+1];
		
			strcpy(addr, faddr);
			strcpy(phone, fphone);
	
		}
		
		void ShowMyFriendDetailInfo()
		{
			ShowMyFriendInfo();
			cout<<"주소: "<<addr<<endl;
			cout<<"전화: "<<phone<<endl<<endl;
		}
		
		~MyFriendDetailInfo()
		{
			delete []addr;
			delete []phone;
			
		}
};

int main(void)
{
	MyFriendDetailInfo fdinfo1 ("Lee",40,"Busan","010-1234-5678");
	MyFriendDetailInfo fdinfo2 ("Kim",30,"Suwon","010-5678-1234");
	
	fdinfo1.ShowMyFriendDetailInfo();
	fdinfo2.ShowMyFriendDetailInfo();
	
	return 0;
}
#endif /* START6 */