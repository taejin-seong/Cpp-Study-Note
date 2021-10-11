#include "CarInLine.h"

/*

//p132
1.인라인 함수는 클래스의 선언과 동일한 파일에 저장되어서 컴파일러가 동시에 참조할 수 있게 해야한다.
* CarInLine.h 참고  

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
