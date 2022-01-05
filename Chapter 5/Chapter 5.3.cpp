#include <iostream>

//#define START1
//#define START2
//#define START3
#define START4

using namespace std;





#ifdef START1

//PassObjCopycon.cpp
class SoSimple
{
	private:
		int num;
	
	public:
		SoSimple(int n): num(n) {}
		
		SoSimple(const SoSimple& copy) : num(copy.num)
		{
			cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
		}
		
		void ShowData()
		{
			cout<<"num: "<<num<<endl;
		}
};

void SimpleFunObj(SoSimple ob)
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout<<"함수호출 전"<<endl;
	SimpleFunObj(obj);
	cout<<"함수호출 후"<<endl;
	
	return 0;
}
#endif /* START1 */



#ifdef START2

//ReturnObjCopycon.cpp
class SoSimple
{
	private:
		int num;
	
	public:
		SoSimple(int n) : num(n){}
		
		SoSimple(const SoSimple& copy) : num(copy.num)
		{
			cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
		}
		
		SoSimple& AddNum(int n)
		{
			num += n;
			return *this;
		}
		
		void ShowData()
		{
			cout<<"num: "<<num<<endl;
		}
		
};

SoSimple SimpleFunObj(SoSimple ob)
{
	cout<<"return 이전"<<endl;
	
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFunObj(obj).AddNum(30).ShowData();
	obj.ShowData();
	
	return 0;
}
#endif /* START2 */




#ifdef START3

//IKonwTempObj.cpp
class Temporary
{
	private:
		int num;
	
	public:
		Temporary(int n) : num(n)
		{
			cout<<"create obj: "<<num<<endl;
		}
		
		~Temporary()
		{
			cout<<"destroy obj: "<<num<<endl;
		}
		
		void ShowTempInfo()
		{
			cout<<"My num is "<<num<<endl;
		}
};

int main(void)
{
	Temporary(100);
	cout<<"********** after make!"<<endl<<endl;

	Temporary(200).ShowTempInfo();
	cout<<"********** after make!"<<endl<<endl;

	const Temporary &ref=Temporary(300);
	cout<<"********** end of main!"<<endl<<endl;
	return 0;
}

#endif /* START3 */





#ifdef START4

//ReturnObjDeadTime.cpp
class SoSimple
{
	private:
		int num;
	
	public:
		SoSimple(int n) : num(n)
		{
			cout<<"New Object: "<<this<<endl;	
		}
		
		SoSimple(const SoSimple& copy) : num(copy.num)
		{
			cout<<"New Copy obj"<<this<<endl;
		}
		
		~SoSimple()
		{
			cout<<"Destroy obj"<<this<<endl;
		}
};

SoSimple SimpleFunObj(SoSimple ob)
{
	cout<<"Parm ADR: "<<&ob<<endl;
	
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFunObj(obj);
	
	cout<<endl;
	SoSimple tempRef = SimpleFunObj(obj);
	cout<<"Return Obj"<<&tempRef<<endl;
	
	return 0;
}
#endif /* START4 */
