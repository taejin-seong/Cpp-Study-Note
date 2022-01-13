#include <iostream>
#include "PointTemplate.h"
//#include "PointTemplate.cpp" 

using namespace std;

int main(void)
{
	Point<int> pos1(3,4);
	pos1.ShowPosition();
	
	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();
	
	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	
	return 0;
}

/*
                              *컴파일 에러 발생* 

-> 파일단위 컴파일 원칙에 의해 PointMain.cpp를 컴파일하면서 PointTemplate.cpp의 내용을 참조하지 않고,
   PointTemplate.cpp를 컴파일 할 때도 PointMain.cpp내용을 참조하지 않음
 
 
 ~  헤더파일 PointTemplate.h에 템플릿 Point의 생성자와 멤버함수의 정의를 삽입
 ~  또는 PointMain.cpp에 #include "PointTemplate.cpp"삽입.
 
*/
