#include <iostream>

//#define START1
//#define START2			
//#define START3
//#define START4
//#define START5
#define START6

using namespace std;





#ifdef START1

//CComStatic.cpp
void Counter()
{
	static int cnt;
	cnt ++;
	
	cout<<"Current cnt: "<<cnt<<endl;
}

int main(void)
{
	for(int i=0; i<10; i++)
	{
		Counter();
	}
	
	return 0;
}
#endif /* START1 */




#ifdef START2

//NeedGlobal.cpp

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
	public:
		SoSimple()
		{
			simObjCnt++;
			cout<<simObjCnt<<"¹øÂ° SoSimple °´Ã¼"<<endl;
		}
};

class SoComplex
{
	public:
		SoComplex()
		{
			cmxObjCnt++;
			cout<<cmxObjCnt<<"¹øÂ° SoComplex °´Ã¼"<<endl;
		}
		
		SoComplex(SoComplex &copy)
		{
			cmxObjCnt ++;
			cout<<cmxObjCnt<<"¹øÂ° SoComplex °´Ã¼"<<endl;
		}
};

int main(void)
{
	SoSimple  sim1;
	SoSimple  sim2;
	
	SoComplex com1;
	SoComplex com2 = com1;
	
	SoComplex();
	
	return 0;
}
#endif /* START2 */





#ifdef START3

//StaticMember.cpp
class SoSimple
{
	private:
		static int simObjCnt;
	
	public:
		SoSimple()
		{
			simObjCnt ++;
			cout<<simObjCnt<<"¹ø¤Š SoSimple °´Ã¼"<<endl;
		}
};

int SoSimple::simObjCnt = 0;

class SoComplex
{
	private:
		static int cmxObjCnt;
		
	public:
		SoComplex()
		{
			cmxObjCnt ++;
			cout<<cmxObjCnt<<"¹øÂ° SoComplex °´Ã¼"<<endl;
		}
		
		SoComplex(SoComplex &copy)
		{
			cmxObjCnt ++;
			cout<<cmxObjCnt<<"¹øÂ° SoComplex °´Ã¼"<<endl;
		}
};

int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple  sim1;
	SoSimple  sim2;
	
	SoComplex com1;
	SoComplex com2 = com1;
	
	SoComplex();
	
	return 0;
}
#endif /* START3 */





#ifdef START4 

//PublicStaticMember.cpp
class SoSimple
{
	public:
		static int simObjCnt;
	
	public:
		SoSimple()
		{
			simObjCnt++;
		}
};

int SoSimple::simObjCnt = 0;


int main(void)
{
	cout<<SoSimple::simObjCnt<<"¹ø¤Š SoSimple °´Ã¼"<<endl;
	SoSimple sim1;
	SoSimple sim2;
	
	cout<<SoSimple::simObjCnt<<"¹øÂ° SoSimple °´Ã¼"<<endl;
	cout<<sim1.simObjCnt<<"¹øÂ° SoSimple °´Ã¼"<<endl;
	cout<<sim2.simObjCnt<<"¹øÂ° SoSimple °´Ã¼"<<endl;
	 
	return 0;
} 
#endif /* START4 */




#ifdef START5

//ConstStaticMember.cpp
class CountryArea
{
	public:
		const static int RUSSIA       =1707540;
		const static int CANADA       =998467;
		const static int CHINA        =957290;
		const static int SOUTH_KOREA  =9922;
		
};

int main(void)
{
	cout<<"·¯½Ã¾Æ ¸éÀû: "<<CountryArea::RUSSIA<<"§´"<<endl;
	cout<<"Ä³³ª´Ù ¸éÀû: "<<CountryArea::CANADA<<"§´"<<endl;
	cout<<"  Áß±¹ ¸éÀû: "<<CountryArea::CHINA<<"§´"<<endl;
	cout<<"  ÇÑ±¹ ¸éÀû: "<<CountryArea::SOUTH_KOREA<<"§´"<<endl; 
	
	return 0;
}
#endif /* START5 */




#ifdef START6

//Mutable.cpp
class SoSimple
{
	private:
		int num1;
		mutable int num2;
		
	public:
		SoSimple(int n1, int n2) : num1(n1), num2(n2){}
		
		void ShowSimpleData() const
		{
			cout<<num1<<", "<<num2<<endl;
		}
		
		void CopyToNum2() const
		{
			num2 = num1;
		}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();	
	sm.ShowSimpleData();
	
	return 0;
}
#endif /* START6 */