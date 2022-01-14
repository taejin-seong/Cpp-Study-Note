#include <iostream>

//#define START1
#define START2


using namespace std;


#ifdef START1

//FunctionTemplateStaticVar.cpp
template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout<<num<<" ";
}




int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout<<endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout<<endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	
	return 0;
	
}
#endif  /* START1 */





#ifdef START2

//ClassTemplateStaticMem.cpp
template <typename T>
class SimpleStaticMem
{
	private:
		static T mem;
	
	public:
		void AddMem(T num)
		{
			mem += num;
		}
		
		
		void ShowMem()
		{
			cout<<mem<<endl;
		}
};




template <typename T>
T SimpleStaticMem<T>::mem = 0; //static 멤버의 초기화 문장

/*
template <>
long SimpleStaticMem<long>::mem = 5;

template<>
int SimpleStaticMem<int>::mem = 1;
*/




int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();
	
	
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	
	return 0;
	
}
#endif /* START2 */