#include <iostream>

#define START1


using namespace std;


#ifdef START1

//ProtectedHeri.cpp
class Base
{
	private:
		int num1;
	
	protected:
		int num2;
		
	public:
		int num3;
		
		Base() : num1(1), num2(2), num3(3) {}
};

class Derived : protected Base {}; //empty

int main(void)
{
	Derived drv;
	cout<<drv.num3<<endl;  //컴파일 에러 발생 Derived 클래스는 Base 클래스를 protected로 상속받았으므로 
	                       //Derived 클래스에서 protected 멤버가 됨. 그로 인해 외부에서는 접근불가  
	return 0;
}

#endif /* START1 */ 
