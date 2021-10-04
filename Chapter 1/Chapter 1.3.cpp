#include <iostream> 
#define START4





#ifdef START1
/*
1.C++의 함수는 '디폴트 값'이라는 것을 설정할 수 있는데, '디폴트 값'이란 기본적으로 설정되어 있는 값. 
2. 함수호출 시 인자를 전달하지 않으면 '디폴트 값'이 전달된 것으로 간주.
3. 전달되는 인자는 왼쪽에서 부터 채워져 나가고, 부족분은 디폴트 값으로 채워진다. 
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









#ifdef START2
/*
1. '디폴트 값은' 함수의 원형 선언에만 위치한다. 
*/


//DefaultValue1.cpp
int Adder(int num=1, int num2=2);	// 함수의 원형 선언에만 매개변수의 디폴트 값이 위치한다. 

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









#ifdef START3
/*

1. 오른쪽 매개변수의 디폴트 값을 비우는 형태로는 디폴트 값을 지정할 수 없다.

ex) int Adder(int num1=10, int num2, int num3);    X
    int Adder(int num1=10, int num2=10, int num3); X
    
ex) int Adder(int num1, int num2, int num3=10); 	  O
    int Adder(int num1, int num2=10, int num3=10); 	  O    
    int Adder(int num1=10, int num2=10, int num3=10);	O    

함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문에..
 
*/


//DefaultValue3.cpp
int BoxVolume(int length, int width=1, int height=1);

int main(void)
{
	std::cout<<"[3,3,3] : "<<BoxVolume(3, 3, 3)<<std::endl;
	std::cout<<"[5,5,D] : "<<BoxVolume(3, 5)<<std::endl;
	std::cout<<"[7,D,D] : "<<BoxVolume(7)<<std::endl;
//	std::cout<<"[D,D,D] : "<<BoxVolume()<<std::endl;   // 모든 매개변수에 디폴트 값이 지정된 것이 아니기 때문에, 인자를 전달하지 않는 형태의 함수 호출은 컴파일 에러. 
	
	return 0;
	
}

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}


#endif /* START3 */






#ifdef START4

//p32 Question 1-3 

//문제1.예제 DefaultValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌, '함수 오버로딩'의 형태로 재 구현해보자. 물론 main 함수는 변경하지 않아야
//하며, 실행 결과도 동일해야 한다.


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




