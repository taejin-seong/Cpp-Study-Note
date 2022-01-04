#include <iostream>

//#define START1
//#define START2
//#define START3
//#define START4
//#define START5
//#define START6
//#define START7
//#define START8
#define START9


using namespace std;



#ifdef START1

//Constructor1.cpp
class SimpleClass
{
	private:
		int num1;
		int num2;
		
	public:
		SimpleClass()
		{
			num1 = 0;
			num2 = 0;
		}
		
		SimpleClass(int n)
		{
			num1 = n;
			num2 = 0;
		}
		
		SimpleClass(int n1, int n2)
		{
			num1 = n1;
			num2 = n2;
		}
		
		/*
		SimpleClass(int n1 = 0, int n2 =0)
		{
			num1 = n1;
			num2 = n2;
		}
		*/
		
		void ShowData() const
		{
			cout<<num1<<' '<<num2<<endl;
			
		}
};

int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();
	
	SimpleClass sc2(100);
	sc2.ShowData();
	
	SimpleClass sc3(100, 200);
	sc3.ShowData();
	
	
	return 0;
}

#endif /* START1 */




#ifdef START2

//Constructor2.cpp
class SimpleClass
{
	private:
		int num1;
		int num2;
		
	public:
		SimpleClass(int n1 = 0, int n2 = 0)
		{
			 num1 = n1;
			 num2 = n2;
			 
		}
		
		void ShowData() const
		{
			cout<<num1<<' '<<num2<<endl;
		}
};

int main(void)
{
	SimpleClass sc1();
	SimpleClass mysc = sc1();
	mysc.ShowData();
		
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20,30);
	return sc;
}

#endif /* START2 */




#ifdef START3

//FruitSaleSim2.cpp
class FruitSeller
{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
	
	public:
		FruitSeller(int price, int num, int money)
		{
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = money;
		}
		
		int SaleApples(int money)
		{
			int num = money/APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			
			return num;
		}
		
		void ShowSalesResult() const
		{
			cout<<"남은 사과: "<<numOfApples<<endl;
			cout<<"판매 수익: "<<myMoney<<endl;
			
		}
};

class FruitBuyer
{
	private:
		int myMoney;
		int numofApples;
	
	public:
		FruitBuyer(int money)
		{
			myMoney = money;
			numofApples = 0;
		}
		
		void BuyApples(FruitSeller &seller, int money)
		{
			numofApples += seller.SaleApples(money);
			myMoney -= money;
		}
		
		void ShowBuyResult() const
		{
			cout<<"현재 잔액: "<<myMoney<<endl;
			cout<<"사과 개수: "<<numofApples<<endl<<endl;
		}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	
	return 0;


}
#endif /* START3 */





#ifdef START4

//FruitSaleSim3.cpp
class FruitSeller
{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
	
	public:
		FruitSeller(int price, int num, int money)
			: APPLE_PRICE(price), numOfApples(num), myMoney(money)
		{
			
		}
		
		int SaleApples(int money)
		{
			int num = money/APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			
			return num;
		}
		
		void ShowSalesResult() const
		{
			cout<<"남은 사과: "<<numOfApples<<endl;
			cout<<"판매 수익: "<<myMoney<<endl;
			
		}
};

class FruitBuyer
{
	private:
		int myMoney;
		int numofApples;
	
	public:
		FruitBuyer(int money)
			: myMoney(money), numofApples(0)
		{
		}
		
		void BuyApples(FruitSeller &seller, int money)
		{
			numofApples += seller.SaleApples(money);
			myMoney -= money;
		}
		
		void ShowBuyResult() const
		{
			cout<<"현재 잔액: "<<myMoney<<endl;
			cout<<"사과 개수: "<<numofApples<<endl<<endl;
		}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	
	return 0;


}
#endif /* START4 */





#ifdef START5

//ReferenceMember.cpp
class AAA
{
	public:
		AAA()
		{
			cout<<"empty object"<<endl;
		}
		
		void ShowYourName()
		{
			cout<<"I'm class AAA"<<endl;
		}
		
};
 
 
 class BBB
 {
 	private:
 		AAA &ref;
 		const int &num;
 		
 	public:
 		BBB(AAA &r, const int &n)
 			: ref(r), num(n)
 		{
 			//empty constructor body
		}
		
		void ShowYourName()
		{
			ref.ShowYourName();
			cout<<"and"<<endl;
			cout<<"I ref num"<<num<<endl;
		}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
		
	return 0;
} 
#endif /* START5 */






#ifdef START6

//PrivateConstructor.cpp
class AAA
{
	private:
		int num;
	
	public:
		AAA() :num(0)
		{
		}
		
		AAA& CreateInitObj(int n) const
		{
			AAA * ptr = new AAA(n);
			return *ptr;
		}
		
		void ShowNum() const
		{
			cout<<num<<endl;
		}
		
		private:
			AAA(int n) : num(n) 
			{
				
			}
};

int main(void)
{
	AAA base;
	base.ShowNum();
	
	AAA &obj1 = base.CreateInitObj(3);
	obj1.ShowNum();
	
	AAA &obj2 = base.CreateInitObj(12);
	obj2.ShowNum();
	
	delete &obj1;
	delete &obj2;
	
	return 0;
}
#endif /* START6 */




#ifdef START7

#include <cstring>

//Destructor.cpp
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
	
	void ShowPersonInfo() const
	{
		cout<<"이름: "<<name<<endl;
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
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	return 0;
}

#endif /* START7 */





#ifdef START8

//p190 Question 4-3 NO.1
class Point 
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x, int y) :xpos(x), ypos(y) {}
		
		void ShowPointInfo() const
		{ 
			cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;	
		}
};

class Circle
{
	private:
		Point po;
		int radius;
	
	public:
		Circle(int x, int y, int r) : po(x,y)
		{

			radius = r;
			
		}
		
		void ShowCircleInfo() const
		{
			cout<<"radius: "<<radius<<endl;
			po.ShowPointInfo();
			
		}
					
};


class Ring
{
	private:
		Circle inner_cir;
		Circle outter_cir;
		
	public:
		Ring(int x1, int y1, int r1, int x2, int y2, int r2) : inner_cir(x1,y1,r1), outter_cir(x2,y2,r2) {}
		
		void ShowRingInfo() const
		{
			cout<<"Inner Circle Info... "<<endl;
			inner_cir.ShowCircleInfo();
			cout<<"Outter Circle Info... "<<endl;
			outter_cir.ShowCircleInfo();			
			
		}
};

int main(void)
{
	Ring ring(1,1,4,2,2,9);
	ring.ShowRingInfo();
	
	return 0;
}


#endif /* START8 */





#ifdef START9

//p190 Question 4-3 NO.2
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

#endif /* START9 */