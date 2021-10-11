#include "Car.h"

/*

// p127
1. C++에서의 파일분할 

* Car.h      : 클래스의 선언을 담는다.
* Car.cpp    : 클래스의 정의(멤버함수의 정의)를 담는다.
* RacingMain : 실질적인 프로그램 


*/

int main(void)
{
	Car run99;
	
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	return 0;
}
