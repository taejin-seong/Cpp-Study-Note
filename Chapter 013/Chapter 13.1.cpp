#include <iostream>
#include <cstring>

//#define START1
//#define START2
//#define START3
//#define START4
//#define START5
//#define START6
#define START7


using namespace std;


#ifdef START1

//AddFunctionTemplate.cpp
template <typename T> 
T Add(T num1, T num2)
{
	return num1 + num2;
}


int main(void)
{
	cout<<Add<int>(15, 20)       <<endl;
	cout<<Add<double>(2.9, 3.7)  <<endl;
	cout<<Add<int>(3.2 , 3.2)    <<endl;
	cout<<Add<double>(3.14, 2.75)<<endl;
	
	return 0;
}
#endif /* START1 */






#ifdef START2

//TwoTypeAddFunction.cpp
template <typename T>
T Add(T num1, T num2)
{
	cout<<"T Add(T num1, T num2)"<<endl;
	return num1 + num2;
}


int Add(int num1, int num2)
{
	cout<<"Add(int num1, int num2)"<<endl;
	return num1 + num2;
}


double Add(double num1, double num2)
{
	cout<<"Add(double num1, duble num2)"<<endl;
	return num1 + num2;
}


int main(void)
{
	cout<<Add(5, 7)      <<endl;
	cout<<Add(3.7, 7.5)  <<endl;
	cout<<Add<int>(5, 7)      <<endl;
	cout<<Add<double>(3.7, 7.5)  <<endl;
	
	return 0;
	
}
#endif /* START2 */





#ifdef START3

//PrimitiveFunctionTemplate.cpp
template <class T1, class T2>
void ShowData(double num)
{
	cout<<(T1)num<<", "<<(T2)num<<endl;
}



int main(void)
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	
	return 0;
}
#endif /* START3 */





#ifdef START4

//p535 Question 13-1 NO.1
class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
};


template <class T>
void SwapData(T& data1, T& data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}


main(void)
{
	Point pos1(3,4);
	Point pos2(10, 20);
	SwapData(pos1, pos2);
	pos1.ShowPosition();
	pos2.ShowPosition();
	
	return 0;
}
#endif /* START4 */







#ifdef START5

//p536 Question 13-1 NO.2
template <class T>
T SumArray(T arr[], int len)
{
	T sum = (T)0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	
	return sum;
}



int main(void)
{
	int arr1[] = {10 ,20, 30 ,40};
	cout<<SumArray(arr1, sizeof(arr1)/sizeof(int))<<endl;
	
	double arr2[] = {10.3, 20.9, 30,5, 40.3};
	cout<<SumArray(arr2, sizeof(arr2)/ sizeof(double))<<endl;
	
	return 0;
}
#endif /* START5 */







#ifdef START6

//NeedSpecialFunctionTemplate.cpp
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}


int main(void)
{
	cout<< Max(11, 15)<<endl;
	cout<< Max('T','Q')<<endl;
	cout<< Max(3.5, 7.5)<<endl;
	cout<< Max("Simple", "Best")<<endl;
	
	return 0;
}
#endif /* START6 */






#ifdef START7

//SpecialFunctionTemplate.cpp
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}



template <>
char* Max(char* a, char* b)
{
	cout<<"char* Max<char*> (char* a, char* b)"<<endl;
	return strlen(a) > strlen(b) ? a : b;
}




template <>
const char* Max(const char* a, const char* b)
{
	cout<<"const char* Max<const char*> (const char* a, const char* b)"<<endl;
	return strcmp(a, b) > 0 ? a : b;
}




int main(void)
{
	cout<<Max(11, 15)           <<endl;
	cout<<Max('T', 'Q')         <<endl;
	cout<<Max(3.5, 7.5)         <<endl;
	cout<<Max("Simple", "Best") <<endl;
	
	char str1[] = "Simple";
	char str2[] = "Best";
	
	cout<<Max(str1, str2)       <<endl;
	
	return 0;
}
#endif /* START7 */