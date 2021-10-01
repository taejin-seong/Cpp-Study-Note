#include <iostream>

/*

1. C++은 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 가능. 
2. C++은 호출할 함수를 찾을 때 '함수의 이름', '매개변수의 선언'의 정보를 활용.
3. 함수의 이름은 같으나 매개 변수형이나 개수가 다른 함수를 가르켜 'overloading 되었다' 라고 한다. 
4. 반환형의 차이는 함수 오버로딩의 조건을 만족시키지 않는다. 

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
	
void MyFunc(int a, int b, int c)	// 매개 변수의 갯수가 다름. overloading 관계가 유지됨. 
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

//문제1. 다음 main 함수에서 필요로 하는 swap 함수를 오버로딩 해서 구현해보자. 


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
	
