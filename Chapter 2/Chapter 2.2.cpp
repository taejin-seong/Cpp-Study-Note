#include <iostream> 

#define START2

using namespace std;


#ifdef START1
/*
1. ture�� false�� 1�� 0�� �ƴ϶� '��'�� '����'�� ǥ���ϱ� ���� 1byte ũ���� ������. 
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
1. true�� false�� ������ �� �ִ� ������ ���� ����ϴ� ���� bool �ڷ���. 
2. ��, bool���� ������ �� �ִ� �����ʹ�  true �ƴ� false��.  
*/

//DataTypeBool.cpp
bool IsPositive(int num)  // bool�� �⺻�ڷ����̱� ������ �Լ��� ��ȯ�����ε� ������ ����. 
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
	bool isPos;  // bool�� ������ ����, �� �������� ture �Ǵ� false�� ������ �� �ִ�. 
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



























