#include <iostream> 
#define START4





#ifdef START1
/*
1.C++�� �Լ��� '����Ʈ ��'�̶�� ���� ������ �� �ִµ�, '����Ʈ ��'�̶� �⺻������ �����Ǿ� �ִ� ��. 
2. �Լ�ȣ�� �� ���ڸ� �������� ������ '����Ʈ ��'�� ���޵� ������ ����.
3. ���޵Ǵ� ���ڴ� ���ʿ��� ���� ä���� ������, �������� ����Ʈ ������ ä������. 
*/


//DefaultValue1.cpp
int Adder(int num1=1, int num2=2)
{
	return num1+num2;
}

int main(void)
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3,5)<<std::endl;
	
	return 0;
}

#endif /* START1 */







/*
1. '����Ʈ ����' �Լ��� ���� ���𿡸� ��ġ�Ѵ�. 
*/


#ifdef START2

//DefaultValue1.cpp
int Adder(int num=1, int num2=2);	// �Լ��� ���� ���𿡸� �Ű������� ����Ʈ ���� ��ġ�Ѵ�. 

int main(void)
{
	std::cout<<Adder()<<std::endl;
	std::cout<<Adder(5)<<std::endl;
	std::cout<<Adder(3,5)<<std::endl;
	
	return 0;
		
}

int Adder(int num1, int num2)	
{
	return num1+num2;
}

#endif /* START2 */






/*

1. ������ �Ű������� ����Ʈ ���� ���� ���·δ� ����Ʈ ���� ������ �� ����.

ex) int Adder(int num1=10, int num2, int num3);    X
    int Adder(int num1=10, int num2=10, int num3); X
    
ex) int Adder(int num1, int num2, int num3=10); 	  O
    int Adder(int num1, int num2=10, int num3=10); 	  O    
    int Adder(int num1=10, int num2=10, int num3=10);	O    

�Լ��� ���޵Ǵ� ���ڰ� ���ʿ������� ���������� ä������ ������..
 
*/


#ifdef START3

//DefaultValue3.cpp
int BoxVolume(int length, int width=1, int height=1);

int main(void)
{
	std::cout<<"[3,3,3] : "<<BoxVolume(3, 3, 3)<<std::endl;
	std::cout<<"[5,5,D] : "<<BoxVolume(3, 5)<<std::endl;
	std::cout<<"[7,D,D] : "<<BoxVolume(7)<<std::endl;
//	std::cout<<"[D,D,D] : "<<BoxVolume()<<std::endl;   // ��� �Ű������� ����Ʈ ���� ������ ���� �ƴϱ� ������, ���ڸ� �������� �ʴ� ������ �Լ� ȣ���� ������ ����. 
	
	return 0;
	
}

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}


#endif /* START3 */






#ifdef START4

//p32 Question 1-3 

//����1.���� DefaultValue3.cpp�� ���ǵ� �Լ� BoxVolume�� '�Ű������� ����Ʈ �� ����' ���°� �ƴ�, '�Լ� �����ε�'�� ���·� �� �����غ���. ���� main �Լ��� �������� �ʾƾ�
//�ϸ�, ���� ����� �����ؾ� �Ѵ�.


int BoxVolume(int a, int b, int c)
{
	return a*b*c;	
} 
 
int BoxVolume(int a, int b)
{
	return a*b;	
} 

int BoxVolume(int a)
{
	return a;	
} 
  
int main(void)
{
	std::cout<<"[3,3,3] : "<<BoxVolume(3, 3, 3)<<std::endl;
	std::cout<<"[5,5,D] : "<<BoxVolume(3, 5)<<std::endl;
	std::cout<<"[7,D,D] : "<<BoxVolume(7)<<std::endl;
//	std::cout<<"[D,D,D] : "<<BoxVolume()<<std::endl;
	
	return 0;
	
} 
#endif /* START4 */ 




