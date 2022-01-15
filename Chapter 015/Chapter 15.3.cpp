#include <iostream>
#include <cstring>
#include <cmath>


//#define START1
//#define START2
//#define START3
#define  START4


using namespace std;


#ifdef START1

//PassException.cpp
void Divide (int num1, int num2)
{
	if(num2 == 0)
	{
		throw num2;
	}
	
	cout<<"나눗셈의 몫: "<< num1/ num2 <<endl;
	cout<<"나눗셈의 나머지: "<< num1%num2 <<endl;
}



int main(void)
{
	int num1, num2;
	cout<<"두 개의 숫자 입력: ";
	cin>>num1>>num2;
	
	try
	{
		Divide(num1, num2);
		cout<<"나눗셈을 마쳤습니다."<<endl;
	}
	
	catch(int expn)
	{
		cout<<"제수는 "<<expn<<"이 될 수 없습니다."<<endl;
		cout<<"프로그램을 다시 실행하세요."<<endl;
	}
	
	return 0;
}
#endif /* START1 */






#ifdef START2

//DiffHandingPosition.cpp
int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;
	
	for (int i = 0; i < len; i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			throw str[i];
		}
		
		num += (int)(pow((double) 10, (len-1)-i) * (str[i]+(7-'7')));
	}
	
	return num;
}




int main(void)
{
	char str1[100];
	char str2[200];
	
	while(1)
	{
		cout<<"두 개의 숫자 입력: ";
		cin>>str1>>str2;
		
		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1) + StoI(str2) <<endl;
			break;
		}
		
		catch(char ch)
		{
			cout<<"문자 "<<ch<<"가 입력되었습니다."<<endl;
			cout<<"재입력 진행합니다."<<endl<<endl; 
		}
	}
	
	cout<<"프로그램을 종료합니다."<<endl;
	
	return 0; 
}
#endif /* START2 */






#ifdef START3

//Stack Unwinding.cpp
void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);


int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	
	catch(int expn)
	{
		cout<<"예외코드: "<<expn<<endl;
	}
	
	return 0;
}




void SimpleFuncOne(void)
{
	cout<<"SimpleFuncOne(void)"<<endl;
	SimpleFuncTwo();
}





void SimpleFuncTwo(void)
{
	cout<<"SimpleFuncTwo(void)"<<endl;
	SimpleFuncThree();
}




void SimpleFuncThree(void)
{
	cout<<"SimpleFuncThree(void)"<<endl;
	throw -1;
}


#endif /* START3 */






#ifdef START4

///CatchList.cpp
int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;
	
	if(len != 0 && str[0]=='0')
	{
		throw 0;
	}
	
	for (int i = 0; i < len; i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			throw str[i];
		}
		
		num += (int)(pow((double) 10, (len-1)-i) * (str[i]+(7-'7')));
	}
	
	return num;
}




int main(void)
{
	char str1[100];
	char str2[200];
	
	while(1)
	{
		cout<<"두 개의 숫자 입력: ";
		cin>>str1>>str2;
		
		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1) + StoI(str2) <<endl;
			break;
		}
		
		catch(char ch)
		{
			cout<<"문자 "<<ch<<"가 입력되었습니다."<<endl;
			cout<<"재입력 진행합니다."<<endl<<endl; 
		}
		
		catch(int expn)
		{
			if(expn == 0)
			{
				cout<<"0으로 시작하는 숫자는 입력불가."<<endl;
			}
			
			else
			{
				cout<<"비정상적 입력이 이루어졌습니다."<<endl;
			}
			
			cout<<"재입력 진행합니다."<<endl<<endl;
		}
	}
	
	cout<<"프로그램을 종료합니다."<<endl;
	
	return 0; 
}

#endif /* START4 */
