#include <iostream>


//#define START1
//#define START2
#define START3


using namespace std;





#ifdef START1

//RealObjUnder1.cpp
class Data
{
	private:
		int data;
	
	public:
		Data(int num) : data(num) { }
		
		void ShowData()
		{
			cout<<"Data: "<<data<<endl;
		}
		
		void Add(int num)
		{
			data += num;
		}
};


int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	
	return 0;
}
#endif /* START1 */





#ifdef START2

//RealObjUnder2.cpp
typedef struct Data
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);

}Data;

void ShowData(Data* THIS)
{
	cout<<"Data: "<<THIS->data<<endl;;
}

void Add(Data* THIS, int num)
{
	THIS->data += num;
}

//적절히 변경된 main함수
int main(void)
{
	Data obj1 = {15, ShowData, Add};
	Data obj2 = { 7, ShowData, Add};
	
	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 15);
	
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	
	return 0;
 } 
#endif /* START2 */




#ifdef START3

//Virtuallnternal.cpp
class AAA
{
	private:
		int num1;
	
	public:
		virtual void Func1()
		{
			cout<<"Func1"<<endl;
		}
		
		virtual void Func2()
		{
			cout<<"Func2"<<endl;
		}
};


class BBB : public AAA
{
	private:
		int num2;
		
	public:
		virtual void Func1()
		{
			cout<<"BBB::Func1"<<endl;
		}
		
		void Func3()
		{
			cout<<"Func3"<<endl;
		}
};


int main(void)
{
	AAA* aptr = new AAA();
	aptr->Func1();
	
	BBB* bptr = new BBB();
	bptr->Func1();
	
	return 0; 
}
#endif /* START3 */
