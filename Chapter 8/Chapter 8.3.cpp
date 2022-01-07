#include <iostream>
#include <cstring>


//#define START1
#define START2


using namespace std;





#ifdef START1

//VirtualDestructor.cpp
class First
{
	private:
		char* strOne;
	
	public:
		First(char* str)
		{
			strOne = new char[strlen(str)+1];
		}
		
		virtual ~First() // 가상 소멸자 
		{
			cout<<"~First()"<<endl;
			delete []strOne;
		}
};


class Second : public First
{
	private:
		char* strTwo;
		
	public:
		Second(char* str1, char* str2) : First(str1)
		{
			strTwo = new char[strlen(str2)+1];
		}
		
		~Second()
		{
			cout<<"~Second()"<<endl;
			delete []strTwo;
		}
};


int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;
	
	return 0;
}
#endif /* START1 */






#ifdef START2

//ReferenceAttribute.cpp
class First
{
	public:
		void FirstFunc()
		{
			cout<<"FirstFun()"<<endl;
		}
		
		virtual void SimpleFunc()
		{
			cout<<"First's SimpleFunc()"<<endl;
		}
};


class Second : public First
{
	public:
		void SecondFunc()
		{
			cout<<"SecondFunc()"<<endl;
		}
		
		virtual void SimpleFunc()
		{
			cout<<"Second's SimpleFunc()"<<endl;
		}
};


class Third : public Second
{
	public:
		void ThirdFunc()
		{
			cout<<"ThirdFunc()"<<endl;
		}
		
		virtual void SimpleFunc()
		{
			cout<<"Third's SimpleFunc"<<endl;
		}
};


int main(void)
{
	Third obj;	
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();
	
	Second &sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();
	
	First &fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
	
	return 0;
}
#endif /* START2 */
