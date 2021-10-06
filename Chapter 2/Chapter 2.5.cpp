#include <iostream>
#include <string.h>
#include <stdlib.h>  // C++에서 C언어의 헤더파일을 추가하는 것도 가능. 

#define START4

using namespace std;




#ifdef START1
/*
1. malloc과 free : 할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야한다..
                 : 자료형이 결정되지 않은 void형 포인터가 반환됨.
				 
2. new와 delete  : C++에서는 내가 힙 영역에 할당하고자 것을 직접 명시했기 때문에 명시한 대상에 맞게 적절히 포인터형이 반환된다. 
                 : ex)
                   int형 변수 -> int형 포인터로 반환  
*/

//MemMalFree.cpp
char * MakeStrAdr(int len)
{
	char * str = (char*)malloc(sizeof(char)*len);
	return str; 
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	free(str);
	
	return 0;
}

#endif /* START1 */




#ifdef START2
/*
1. new 연산자를 사용해서 힙에 있는 메모리를 동적할당
2. delete를 사용해서 할당된 메모리 공간을 소멸 
*/

//NewDelete.cpp
char * MakeStrAdr(int len)
{
	//char * str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len]; // new를 사용하여 메모리를 동적할당. 
	return str;
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	//free(str);
	delete []str;  // 소멸하고자 하는 것이 배열의 형태라면 delete []str처럼 []를 추가로 배열임을 명시해야한다. 
	
	return 0;
}

#endif /* START2 */




#ifdef START3
/*
1. new와 malloc 함수의 동작방식에는 차이가 있다.
2. 결과만 보면 메모리 할당이라는 측면에서는 유사하지만 하는 일에 대하여는 차이가 있다. 
*/

//NewObject.cpp
class Simple
{
public:
	Simple()
	{
		cout<<"I'm simple constructorl!"<<endl;
	}
};

int main(void)
{
	cout<<"case 1: ";
	Simple * sp1 = new Simple;
	
	cout<<"case 2: ";
	Simple * sp2 = (Simple*)malloc(sizeof(Simple)*1);
	
	cout<<endl<<"end of main"<<endl;
	delete sp1;
	free(sp2);
	
	return 0;
}

#endif /* START2 */




#ifdef START4

//p95 Question 2-3

//문제1. 책 참 고 

typedef struct __Point
{
	int xpos;
	int ypos;
	
}Point;


Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *pptr = new Point;
	
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p1.ypos;
	
	return *pptr;
}
 
int main(void)
{
	Point *pptr1 = new Point;
	pptr1->xpos = 13;
	pptr1->ypos = 10;
	
	Point *pptr2 = new Point;
	pptr2->xpos = 43;
	pptr2->ypos = 40;
	
	Point &pref = PntAdder(*pptr1, *pptr2);
	cout<<"["<<pref.xpos<<","<<pref.ypos<<"]"<<endl;
	
	delete pptr1;
	delete pptr2;
	delete &pref;
	
	return 0;		
}
 
#endif /* START4 */
 
