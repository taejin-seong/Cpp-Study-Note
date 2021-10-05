#include <iostream> 

#define START2

using namespace std;


#ifdef START1
/*
1. ture와 false는 1과 0이 아니라 '참'과 '거짓'을 표현하기 위한 1byte 크기의 데이터. 
*/

//TrueAndFalse.cpp
int main(void)
{
	int num = 10;
	int i = 0;
	
	cout<<"true: "<<true<<endl;
	cout<<"false: "<<false<<endl;
	
	while(true)
	{
		cout<<i++<<' ';
		
		if(i>num)
		{
			break;
		}
		
	}
	
		cout<<endl;
		
		cout<<"sizeof 1: "<<sizeof(1)<<endl;
		cout<<"sizeof 0: "<<sizeof(0)<<endl;
		cout<<"sizeof true: "<<sizeof(true)<<endl;
		cout<<"sizeof flase: "<<sizeof(false)<<endl;
		
		return 0;
		
	
}

#endif /* START1 */




#ifdef START2
/*
1. true나 false를 저장할 수 있는 변수의 선언에 사용하는 것이 bool 자료형. 
2. 즉, bool형에 저장할 수 있는 데이터는  true 아님 false다.  
*/

//DataTypeBool.cpp
bool IsPositive(int num)  // bool도 기본자료형이기 때문에 함수의 반환형으로도 선언이 가능. 
{
	if(num<=0)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}

int main(void)
{
	bool isPos;  // bool형 변수를 선언, 이 변수에는 ture 또는 false를 저장할 수 있다. 
	int num;
	cout<<"Input number: ";
	cin>>num;
	
	isPos = IsPositive(num);
	
	if(isPos)
	{
		cout<<"Positive number"<<endl;
	}
	
	else
	{
		cout<<"Negative number"<<endl;
	}
	
	return 0;
}

#endif /* START2 */



























