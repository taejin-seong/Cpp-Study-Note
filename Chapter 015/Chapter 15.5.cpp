#include <iostream>
#include <cstring>


//#define START1
#define START2


using namespace std;


#ifdef START1

//BadAlloc.cpp
#include <new> //bad_alloc ����� ���� 

int main(void)
{
	int num = 0;
	
	try
	{
		while(1)
		{
			num++;
			cout<<num<<"��° �Ҵ� �õ�"<<endl;
			new int[10000][10000];
		}
	 }
	 
	 catch(bad_alloc &bad)
	 {
	 	cout<<bad.what()<<endl;
	 	cout<<"�� �̻� �Ҵ� �Ұ�!"<<endl;
	 }
	 
	 return 0;
}
#endif /* STRT1 */





#ifdef START2

//ReThrow.cpp
void Divide(int num1, int num2)
{
	try
	{
		if(num2 == 0)
		{
			throw 0;
		}
		
		cout<<"��: "<<num1/num2<<endl;
		cout<<"������: "<<num1%num2<<endl;

	}
	
	catch(int expn)
	{
		cout<<"first catch"<<endl;
		throw; //���ܸ� �ٽ� ������. 
	}
}


int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	
	
	catch(int expn)
	{
		cout<<"second catch"<<endl;
	}
	
	return 0;
 } 
#endif /* START2 */
