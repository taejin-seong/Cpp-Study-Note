#include <iostream>


//#define START1
#define START2



using namespace std;


#ifdef START1

//UnhandlingException.cpp
int main(void)
{
	int num1, num2;
	cout<<"�� ���� ���� �Է�: ";
	cin>>num1>>num2;
	
	cout<<"�������� ��: "<<num1/num2<<endl;
	cout<<"�������� ������: "<<num1%num2<<endl;
	
	return 0;
}
#endif /* START1 */





#ifdef START2

//HandlingExceptionUseIf.cpp
int main(void)
{
	
	int num1, num2;
	cout<<"�� ���� ���� �Է�: ";
	cin>>num1>>num2;
	
	if (num2 == 0)
	{
		cout<<"������ 0�� �� �� �����ϴ�."<<endl;
		cout<<"���α׷��� �ٽ� �����ϼ���."<<endl;
	}
	
	else
	{
		cout<<"�������� ��: "<<num1/num2<<endl;
		cout<<"�������� ������: "<<num1%num2<<endl;	
	}
	
	return 0;
}
#endif /* START2 */
