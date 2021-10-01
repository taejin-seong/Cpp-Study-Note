#include <iostream> //iostream.h의 구버전과 신버전에 해당하는 헤더파일을 include함.  
 
int main(void)
{


	/*
	 
	 1. 출력을 위해서는 std::cout<< '출력 대상' 형태를 취해한다. 
	 2. C++은 별도의 출력포맷을 지정하지 않아도 데이터의 성격에 따라 적절한 출력이 이루어진다.
	 3. std::endl의 출력은 개행으로 이어진다.
	 4. << 연산자를 이용하면 둘 이상의 출력대상을 연이어서 출력할 수 있다.
	  
	*/
	
// HelloWorld.cpp


	int num = 20;
	std::cout<<"Hello World!"<<std::endl;				 
	std::cout<<"Hello "<<"World!"<<std::endl;
	std::cout<<num<<' '<<'A';
	std::cout<<' '<<3.14<<std::endl;

	return 0;

	
	
	
	/*

	1. 키보드로부터 데이터 입력에는 std::cin과 >>연산자가 사용된다.
	2. 변수의 선언은 어디서든 가능하다.
	3. C++에서는 데이터의 입력도 데이터의 출력과 마찬가지로 별도의 포맷 지정이 필요없다. 
	  (변수의 자료형만 변경하면 된다.) 
  	4. cout : 콘솔 아웃 , cin : 콘솔 인  

	*/
	
//SimpleAdder.cpp

	int val1;
	std::cout<<"첫 번째 숫자입력: ";		
	std::cin>>val1;						
	
	int val2;
	std::cout<<"두 번째 숫자입력: ";
	std::cin>>val2;
	
	int result= val1+val2;
	std::cout<<"덧셈결과: "<<result<<std::endl;

	return 0; 
	




	/*
	
	1. C++의 지역변수 선언은 함수 내 어디든 삽입이 가능하다. 
	 
	*/
	
//BetweenAdder.cpp

	int val1, val2;
	int result = 0;
	std::cout<<"두 개의 숫자입력: ";
	std::cin>>val1>>val2;	// 첫 번째 입력되는 정수가 val1에 저장되고 두 번째 입력되는 정수가 val2에 저장된다. 
						    // 첫 번쨰 정수와 두 번째 정수의 경계는 공백에 의해 나눠진다. 
	
	if(val1<val2)
	{
		for(int i=val1+1; i<val2; i++)	// C++에서는 for문 안에서 선언과 동시에 초기화를 진행한다.  
		result+=i;						// 여기서 i는 for문 안에서만 사용가능한 지역변수. 
	}		
	
	else
	{
		for(int i=val2+i; i<val1; i++)
		result+=i;
	}

	std::cout<<"두 수 사이의 정수 합: "<<result<<std::endl;
	

	return 0;





	/*

	1. C++은 별도의 출력포맷을 지정하지 않아도 데이터의 성격에 따라 적절한 출력이 이루어진다.  
	
	*/

//StringO.cpp
	
	char name[100];	// 문자열 저장을 위한 변수와 배열만 존재한다. 
	char lang[200];
	
	std::cout<<"이름은 무엇입니까? ";
	std::cin>>name;
	
	std::cout<<"좋아하는 프로그래밍 언어는 무엇인가요? ";
	std::cin>>lang;
	
	std::cout<<"내 이름은 "<<name<<"입니다.\n";
	std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다."<<std::endl;
	
	return 0; 
	




//p22 Question 1-1 

//문제1. 사용자로부터 총 5개의 정수를 입력받아서, 그 합을 출력하는 프로그램을 작성해 보자. 단, 프로그램의 실행은 다음과 같이 이뤄저야 한다.
	
	int num[5];
	int result;
	
	for(int i=0; i<5; i++)
	{
		std::cout<<i+1<<" 번째 정수 입력: ";
		std::cin>>num[i];
		result += num[i];		
	}
	
	std::cout<<"합계: "<<result<<std::endl;
	
	return 0;

 
 
//문제2. 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.
	
	char name[100];
	char num[100];
	
	std::cout<<"이름 입력: ";
	std::cin>>name;
	std::cout<<"전화번호 입력: ";
	std::cin>>num;
	
	std::cout<<"이름과 전화번호: "<<name<<" , "<<num;
	
 
 
 
 //문제3. 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자, 예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야한다.
 
 	int num;
	
	std::cout<<"숫자 입력: ";
	std::cin>>num;
	
	for(int i=0; i<10; i++)
	{
		std::cout<<num<<"*"<<i<<"="<<num*i<<std::endl;
	}
	
	return 0; 




//문제4. 판매원들의 급여 계산 프로그램을 작성해 보자. 이 회사는 모든 판매원에게 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급한다. 예를 들어서 민수라는
//		 친구의 이번 달 물품 판매 금액이 100만원 이라면, 50+100*0.12=62, 따라서 62만원을 급여로 지급 받는다. 단, 아래의 실행 예에서 보이듯이 이러한 급여 계산은 -1이 입력
//		 될 때 까지 계속 되어야한다.

	int pay; 
	
	while(pay != -1)
	{
		std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>pay;
		
		if(pay == -1)
		{
			break;
		}
		
		std::cout<<"이번 달 급여: "<<50+pay*0.12<<std::endl;
		

	}
	
	std::cout<<"프로그램을 종료합니다.";
		

 
 
}
