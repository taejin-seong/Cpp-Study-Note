#include <iostream> 
#define START8



#ifdef START1
/*
1. namespace ������ �̸��� �浹�� ���ؼ� ����� ������ ���� �� ����.
2. namespace�� Ư�� �̸��� ������� �Լ��� ������ �׷�ȭ ��Ű�� ����. 
3. ::�� ��������������.  
*/

//NameSp1.cpp
namespace BestComImp1  // BestComImpl �̶�� namespace�� ����. 
{
	void SimpleFunc(void)  // �׸��� �� �ȿ� �Լ� SimpleFunc�� ������. 
	{
		std::cout<<"BestCom�� ������ �Լ�"<<std::endl;  // ���� �� �Լ��� BestComImp1::SimpleFunc�̶�� ��Ī�ϰ� ��. 
	}	
}

namespace ProgComImp1  // ProgComImpl �̶�� namespace�� ����. 
{
	void SimpleFunc(void)  // �׸��� �� �ȿ� �Լ� SimpleFunc�� ������.
	{
		std::cout<<"ProgCom�� ������ �Լ�"<<std::endl;  //  ���� �� �Լ��� ProgComImp1::SimpleFunc�̶�� ��Ī�ϰ� ��. 
	}	
}

int main(void)
{
	BestComImp1::SimpleFunc();	// �̸����� ���� ���ǵ� �Լ��� ȣ���ϴ� ��. �̸�����::ȣ���� �Լ��� 
	ProgComImp1::SimpleFunc();  // ::�� �������� ������(scope resolution operator), �̸������� ������ �� ����ϴ� ������. 
	
	return 0;
	
}
#endif /* START1 */





#ifdef START2
/*
1.�̸����� ��ݿ��� �Լ��� ����� ���Ǹ� �и� �� �� �ִ�. 
*/

//NameSp2.cpp
namespace BestComImp1   
{
	void SimpleFunc(void);	// �Լ��� ������ �ݵ�� �̸������ȿ� ��ġ�ؾ� �Ѵ�. 
}

namespace ProgComImp1 
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImp1::SimpleFunc();	
	ProgComImp1::SimpleFunc();  
	
	return 0;
	
}

void BestComImp1::SimpleFunc(void)  // �Լ��� ���Ǹ� �и� �� �� �ݵ�� ::�� ��� ���Ե� �Լ����� ����ؾ� �Ѵ�. 
{
	std::cout<<"BestCom�� ������ �Լ�"<<std::endl;	
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout<<"ProgCom�� ������ �Լ�"<<std::endl;
}

#endif /* START2 */




#ifdef START3
/*
1.������ �̸������� ���ǵ� �Լ��� ȣ�� �� ������ �̸������� ����� �ʿ䰡 ����. 
*/

//NameSp3.cpp
namespace BestComImp1  // ������ �̸����� 
{
	void SimpleFunc(void);
}

namespace BestComImp1  // ������ �̸����� 
{
	void PrettyFunc(void);
}

namespace ProgComImp1 
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImp1::SimpleFunc();
	
	return 0;
	
}

void BestComImp1::SimpleFunc(void)
{
	std::cout<<"BestCom�� ������ �Լ�"<<std::endl;	
	PrettyFunc();  // ������ �̸������� ���ǵ� �Լ��� ȣ�� �� ������ �̸������� ����� �ʿ䰡 ����. 
	ProgComImp1::SimpleFunc(); // �ٸ� �̸������� ���ǵ� �Լ�  
}

void BestComImp1::PrettyFunc(void)
{
	std::cout<<"So Pretty!!"<<std::endl;	
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout<<"ProgCom�� ������ �Լ�"<<std::endl;
}

#endif /* START3 */




#ifdef START4
/*
1, �̸������� �ٸ� �̸����� �ȿ� ���Ե� �� �ִ�. (�̷а����� ��ø ��ų �� �ִ�.) 
*/

//NameSp4.cpp
namespace Parent   
{
	int num = 2;
	
	namespace SubOne
	{
		int num = 3;
	}
	
	namespace SubTwo
	{
		int num = 4;
	}
	
}


int main(void)
{
	std::cout<<Parent::num<<std::endl;  // ������ �̸������� ����� ������ �����ϴ� ��� 
	std::cout<<Parent::SubOne::num<<std::endl;
	std::cout<<Parent::SubTwo::num<<std::endl;
	
	return 0;
	
}


#endif /* START4 */





#ifdef START5
/*
1,std::cout -> �̸����� std�� ����� cout
  std::cin -> �̸����� std�� ����� cin
  std::endl -> �̸����� std�� ����� endl

ex)
namespace std
{
	cout ...
	cin ....
	endl ...
}


2, using�� �̿��ؼ� �̸����� �ȿ� ����� �Լ��� ������������ �׳� ȣ���� �� �ִ�. 
*/

//UsingDcl1.cpp
namespace Hybrid
{
	void HybFunc(void)
	{
		std::cout<<"So simple function!"<<std::endl;
		std::cout<<"In namespace Hybrid!"<<std::endl;
		
	}
}

int main(void)
{
	using Hybrid::HybFunc; // using�� ����Ͽ� �̸������� �������� �ʰ� ȣ���ϰڴٰ� ����, ���� �Լ��������� ȿ���� ������ using ����. 
	HybFunc();  // ������������ �Լ� ȣ�� 
	
	return 0;
}

#endif /* START5 */





#ifdef START6
/*
1. ���α׷� ��ü������ using ������ ȿ���� ��ġ�� �Ϸ��� ���������� ���������� �Լ� �ۿ� ����  
*/


//UsingDcl2.cpp
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int num=20;
	cout<<"Hello World!"<<endl;
	cout<<"Hello "<<"World"<<endl;
	cout<<num<<' '<<'A';
	cout<<' '<<3.14<<endl;
	
	return 0;
}

#endif /* START6 */





#ifdef START7
/*
1. using namespace std ������ ���� �̸����� std�� ����� ���Ϳ� ���� �̸����� ������ ������ ����� �� ����. 
*/


//UsingDcl3.cpp
using namespace std;

int main(void)
{
	int num=20;
	cout<<"Hello World!"<<endl;
	cout<<"Hello "<<"World"<<endl;
	cout<<num<<' '<<'A';
	cout<<' '<<3.14<<endl;
	
	return 0;
}

#endif /* START7 */





#ifdef START8
/*
1.�̸������� ��Ī�� ������ �� �ִ�. 
*/


//NameAlias.cpp
using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;
	
	namespace ABC = AAA::BBB::CCC; // num1, num2�� �����Ϸ��� �� �� AAA::BBB::CCC�� ���Ͽ�  ��Ī�� ABC�� �����Ͽ� �����ϰ� ������. 
	cout<<ABC::num1<<endl;
	cout<<ABC::num2<<endl;
	
	return 0;
}

#endif /* START8 */





#ifdef START9
/*
1. :: (�������� ������)�� ���������� �ƴ� ���������� ���ٿ��� ��� �����ϴ�.  
*/


//ScopeResolutionOperatorOtherFunction.cpp
using namespace std;
using namespace std;

int val = 100;  // ���� ���� 

int SimpleFunc(void)
{
	int val = 20; // ������ �̸��� ���� ���� 
	val += 3;  // ���� ���� val ���� +3 ���� ��Ŵ 
	::val += 7;  // �̸������� ���� ���� ���� val�� �����Ͽ� +7 ���� ��Ŵ. 
	
	/* ���� ���� val = 100; ���� �̸������� ���� ���� val�� �̸������̱� ������ ::val�� ������ ������. */ 
	/* ex) 
		namespace (����) <- �̸������� �̸��� ���� 
		{
			val = 100;
		}
	*/
}


int main(void)
{
	cout<<SimpleFunc(); // �ᱹ ���������� ������ �������� val���� +7 ������ val = 107�� ��µ�. 
	
	return 0;
}

#endif /* START9 */

