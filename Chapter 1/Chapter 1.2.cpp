#include <iostream>

/*

1. C++�� �Լ�ȣ�� �� ���޵Ǵ� ���ڸ� ���ؼ� ȣ���ϰ��� �ϴ� �Լ��� ������ ����. 
2. C++�� ȣ���� �Լ��� ã�� �� '�Լ��� �̸�', '�Ű������� ����'�� ������ Ȱ��.
3. �Լ��� �̸��� ������ �Ű� �������̳� ������ �ٸ� �Լ��� ������ 'overloading �Ǿ���' ��� �Ѵ�. 
4. ��ȯ���� ���̴� �Լ� �����ε��� ������ ������Ű�� �ʴ´�. 

*/


//Function Overloading.cpp

	void MyFunc(void)
	{
		
		std::cout<<"MyFunc(void) called"<<std::endl;
	
	}
	
	void MyFunc(char c)
	{
		
		std::cout<<"MyFunc(char c) called"<<std::endl;
	
	}
	
	void MyFunc(int a, int b)
	{
		
		std::cout<<"MyFunc(int a, int b) called"<<std::endl;
	
	}
	
	void MyFunc(int a, int b, int c)	// �Ű� ������ ������ �ٸ�. overloading ���谡 ������. 
	{
		
		std::cout<<"MyFunc(int a, int b, int c) called"<<std::endl;
	
	}
	
	
	int main(void)
	{
		MyFunc();
		MyFunc('A');
		MyFunc(12, 13);
		MyFunc(12, 13, 14);
		
		return 0;
		
	}

	

//p26 Question 1-2 

//����1. ���� main �Լ����� �ʿ�� �ϴ� swap �Լ��� �����ε� �ؼ� �����غ���. 


	void swap(int *num1, int *num2)
	{
		int x= *num1;
		*num1 = *num2;
		*num2 = x;
	}
	
	void swap(char *num1, char *num2)
	{
		char x= *num1;
		*num1 = *num2;
		*num2 = x;
	}
	
	void swap(double *num1, double *num2)
	{
		double x= *num1;
		*num1 = *num2;
		*num2 = x;
	}
	
	
	int main(void)
	{
		int num1 = 20, num2 = 30;
		swap(&num1, &num2);
		std::cout<<num1<<' '<<num2<<std::endl;
		
		char ch1 = 'A', ch2 = 'Z';
		swap(&ch1, &ch2);
		std::cout<<ch1<<' '<<ch2<<std::endl;
		
		double db1 = 1.111, db2= 5.555;
		swap(&db1, &db2);
		std::cout<<db1<<' '<<db2<<std::endl;
		
		return 0;		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
