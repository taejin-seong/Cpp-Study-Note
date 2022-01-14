#include <iostream>


//#define START1
#define START2


using namespace std;


#ifdef START1

//ClassTemplateSpecialization.cpp
template <typename T>
class Point
{
	private:
		T xpos, ypos;
	
	public:
		Point(T x = 0, T y = 0) : xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
};



template <typename T>
class SimpleDataWrapper
{
	private:
		T mdata;
	
	public:
		SimpleDataWrapper(T data) : mdata(data)
		{ }
		
		
		void ShowDataInfo(void)
		{
			cout<<"Data: "<<mdata<<endl;
		}
};



template<>
class SimpleDataWrapper<char*>
{
	private:
		char* mdata;
	
	public:
		SimpleDataWrapper(char* data)
		{
			mdata = new char[strlen(data)+1];
			strcpy(mdata, data);
		}
		
		
		void ShowDataInfo(void)
		{
			cout<<"String: "<<mdata<<endl;
			cout<<"Length: "<<strlen(mdata)<<endl;
		}
		
		
		~SimpleDataWrapper()
		{
			delete []mdata;
		}
	
};




template<>
class SimpleDataWrapper < Point<int> >
{
	private:
		Point<int> mdata;
		
	public:
		SimpleDataWrapper(int x, int y) : mdata(x,y)
		{ }
		
		
		void ShowDataInfo(void)
		{
			mdata.ShowPosition();
		}
			
};




int main(void)
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	
	SimpleDataWrapper< Point<int> > poswrap(3, 7);
	poswrap.ShowDataInfo();
	
	return 0;
}
#endif /* START1 */





#ifdef START2

//ClassTemplatePartialSpecialization.cpp
template <typename T1, typename T2>
class MySimple
{
	public:
		void WhoAreYou()
		{
			cout<<"size of T1: "<<sizeof(T1)<<endl;
			cout<<"size of T2: "<<sizeof(T2)<<endl;
			cout<<"<typename T1, typename T2>"<<endl;
		}
};




template <>
class MySimple <int, double>
{
	public:
		void WhoAreYou()
		{
			cout<<"size of T1: "<<sizeof(int)<<endl;
			cout<<"size of T2: "<<sizeof(double)<<endl;
			cout<<"<int, double>"<<endl;
		}
};




template <typename 	T1>
class MySimple <T1, double> //T2를 double로 부분 특수화 
{
	public:
		void WhoAreYou()
		{
			cout<<"size of T1: "<<sizeof(T1)<<endl;
			cout<<"size of T2: "<<sizeof(double)<<endl;
			cout<<"<T1, dobule>"<<endl;
		}
};




int main(void)
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();
	
	MySimple<int, long> obj2;
	obj2.WhoAreYou();
	
	MySimple<int, double> obj3;
	obj3.WhoAreYou();
	
	return 0;
}


#endif /* START2 */