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
	cout<<drv.num3<<endl;  //������ ���� �߻� Derived Ŭ������ Base Ŭ������ protected�� ��ӹ޾����Ƿ� 
	                       //Derived Ŭ�������� protected ����� ��. �׷� ���� �ܺο����� ���ٺҰ�  
	return 0;
}

#endif /* START1 */ 
