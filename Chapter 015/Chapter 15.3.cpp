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
	
	cout<<"�������� ��: "<< num1/ num2 <<endl;
	cout<<"�������� ������: "<< num1%num2 <<endl;
}



int main(void)
{
	int num1, num2;
	cout<<"�� ���� ���� �Է�: ";
	cin>>num1>>num2;
	
	try
	{
		Divide(num1, num2);
		cout<<"�������� ���ƽ��ϴ�."<<endl;
	}
	
	catch(int expn)
	{
		cout<<"������ "<<expn<<"�� �� �� �����ϴ�."<<endl;
		cout<<"���α׷��� �ٽ� �����ϼ���."<<endl;
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
		cout<<"�� ���� ���� �Է�: ";
		cin>>str1>>str2;
		
		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1) + StoI(str2) <<endl;
			break;
		}
		
		catch(char ch)
		{
			cout<<"���� "<<ch<<"�� �ԷµǾ����ϴ�."<<endl;
			cout<<"���Է� �����մϴ�."<<endl<<endl; 
		}
	}
	
	cout<<"���α׷��� �����մϴ�."<<endl;
	
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
		cout<<"�����ڵ�: "<<expn<<endl;
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
		cout<<"�� ���� ���� �Է�: ";
		cin>>str1>>str2;
		
		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1) + StoI(str2) <<endl;
			break;
		}
		
		catch(char ch)
		{
			cout<<"���� "<<ch<<"�� �ԷµǾ����ϴ�."<<endl;
			cout<<"���Է� �����մϴ�."<<endl<<endl; 
		}
		
		catch(int expn)
		{
			if(expn == 0)
			{
				cout<<"0���� �����ϴ� ���ڴ� �ԷºҰ�."<<endl;
			}
			
			else
			{
				cout<<"�������� �Է��� �̷�������ϴ�."<<endl;
			}
			
			cout<<"���Է� �����մϴ�."<<endl<<endl;
		}
	}
	
	cout<<"���α׷��� �����մϴ�."<<endl;
	
	return 0; 
}

#endif /* START4 */
