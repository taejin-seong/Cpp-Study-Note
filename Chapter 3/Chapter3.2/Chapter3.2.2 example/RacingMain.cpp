#include "Car.h"

/*

// p127
1. C++������ ���Ϻ��� 

* Car.h      : Ŭ������ ������ ��´�.
* Car.cpp    : Ŭ������ ����(����Լ��� ����)�� ��´�.
* RacingMain : �������� ���α׷� 


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
