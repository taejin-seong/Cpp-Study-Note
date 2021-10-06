
/*
1. 헤더파일 확장자인 .h를 생략하고 앞에 c를 붙이면 C언어에 대응하는 C++의 헤더파일 이름이 된다.
   따라서 쉽게 C언어 함수를 C++에도 호출할 수 있다. ~ 하위 버전과의 호환성 
   
   
2. C++의 표준헤더를 이용해서 함수를 호출하는 것이 좋다. 
*/


#include <cmath>   /* C버전 헤더파일 호출 */ 
#include <cstdio>
#include <cstring>  

using namespace std;

//StdCPPFunc.cpp
int main(void)
{
	char str1[] = "Result";
	char str2[30];
	
	strcpy(str2, str1);
	printf("%s: %f \n",str1, sin(0.14));
	printf("%s: %f \n",str2, abs(-1.25));
	
	return 0;
	
}

