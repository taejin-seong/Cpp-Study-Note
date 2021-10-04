#include <iostream> 
#define START8



#ifdef START1
/*
1. namespace 문법은 이름의 충돌로 인해서 생기는 문제를 막을 수 있음.
2. namespace는 특정 이름을 대상으로 함수나 변수를 그룹화 시키는 개념. 
3. ::는 범위지정연산자.  
*/

//NameSp1.cpp
namespace BestComImp1  // BestComImpl 이라는 namespace를 만듬. 
{
	void SimpleFunc(void)  // 그리고 그 안에 함수 SimpleFunc를 정의함. 
	{
		std::cout<<"BestCom이 정의한 함수"<<std::endl;  // 따라서 이 함수는 BestComImp1::SimpleFunc이라고 지칭하게 됨. 
	}	
}

namespace ProgComImp1  // ProgComImpl 이라는 namespace를 만듬. 
{
	void SimpleFunc(void)  // 그리고 그 안에 함수 SimpleFunc를 정의함.
	{
		std::cout<<"ProgCom이 정의한 함수"<<std::endl;  //  따라서 이 함수는 ProgComImp1::SimpleFunc이라고 지칭하게 됨. 
	}	
}

int main(void)
{
	BestComImp1::SimpleFunc();	// 이름공간 내에 정의된 함수를 호출하는 법. 이름공간::호출할 함수명 
	ProgComImp1::SimpleFunc();  // ::는 범위지정 연산자(scope resolution operator), 이름공간을 지정할 때 사용하는 연산자. 
	
	return 0;
	
}
#endif /* START1 */





#ifdef START2
/*
1.이름공간 기반에서 함수의 선언과 정의를 분리 할 수 있다. 
*/

//NameSp2.cpp
namespace BestComImp1   
{
	void SimpleFunc(void);	// 함수의 선언은 반드시 이름공간안에 위치해야 한다. 
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

void BestComImp1::SimpleFunc(void)  // 함수의 정의를 분리 할 때 반드시 ::로 어디에 삽입된 함수인지 명시해야 한다. 
{
	std::cout<<"BestCom이 정의한 함수"<<std::endl;	
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}

#endif /* START2 */




#ifdef START3
/*
1.동일한 이름공간에 정의된 함수를 호출 할 때에는 이름공간을 명시할 필요가 없음. 
*/

//NameSp3.cpp
namespace BestComImp1  // 동일한 이름공간 
{
	void SimpleFunc(void);
}

namespace BestComImp1  // 동일한 이름공간 
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
	std::cout<<"BestCom이 정의한 함수"<<std::endl;	
	PrettyFunc();  // 동일한 이름공간에 정의된 함수를 호출 할 때에는 이름공간을 명시할 필요가 없다. 
	ProgComImp1::SimpleFunc(); // 다른 이름공간에 정의된 함수  
}

void BestComImp1::PrettyFunc(void)
{
	std::cout<<"So Pretty!!"<<std::endl;	
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}

#endif /* START3 */




#ifdef START4
/*
1, 이름공간은 다른 이름공간 안에 삽입될 수 있다. (이론공간을 중첩 시킬 수 있다.) 
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
	std::cout<<Parent::num<<std::endl;  // 각각의 이름공간의 선언된 변수에 접근하는 방법 
	std::cout<<Parent::SubOne::num<<std::endl;
	std::cout<<Parent::SubTwo::num<<std::endl;
	
	return 0;
	
}


#endif /* START4 */





#ifdef START5
/*
1,std::cout -> 이름공간 std에 선언된 cout
  std::cin -> 이름공간 std에 선언된 cin
  std::endl -> 이름공간 std에 선언된 endl

ex)
namespace std
{
	cout ...
	cin ....
	endl ...
}


2, using을 이용해서 이름공간 안에 선언된 함수를 범위지정없이 그냥 호출할 수 있다. 
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
	using Hybrid::HybFunc; // using을 사용하여 이름공간을 지정하지 않고 호출하겠다고 선언, 지역 함수내에서만 효력을 가지는 using 선언. 
	HybFunc();  // 범위지정없이 함수 호출 
	
	return 0;
}

#endif /* START5 */





#ifdef START6
/*
1. 프로그램 전체영역에 using 선언의 효력을 미치게 하려면 전역변수와 마찬가지로 함수 밖에 선언  
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
1. using namespace std 선언을 통해 이름공간 std에 선언된 모든것에 대해 이름공간 지정의 생략을 명령할 수 있음. 
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
1.이름공간의 별칭을 지정할 수 있다. 
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
	
	namespace ABC = AAA::BBB::CCC; // num1, num2를 접근하려고 할 때 AAA::BBB::CCC에 대하여  별칭을 ABC로 지정하여 간편하게 접근함. 
	cout<<ABC::num1<<endl;
	cout<<ABC::num2<<endl;
	
	return 0;
}

#endif /* START8 */





#ifdef START9
/*
1. :: (범위지정 연산자)는 지역변수가 아닌 전역변수의 접근에도 사용 가능하다.  
*/


//ScopeResolutionOperatorOtherFunction.cpp
using namespace std;
using namespace std;

int val = 100;  // 전역 변수 

int SimpleFunc(void)
{
	int val = 20; // 동일한 이름의 지역 변수 
	val += 3;  // 지역 변수 val 값을 +3 증가 시킴 
	::val += 7;  // 이름공간을 통해 전역 변수 val에 접근하여 +7 증가 시킴. 
	
	/* 전역 변수 val = 100; 에서 이름공간이 없는 것이 val의 이름공간이기 때문에 ::val로 접근이 가능함. */ 
	/* ex) 
		namespace (공백) <- 이름공간에 이름이 없음 
		{
			val = 100;
		}
	*/
}


int main(void)
{
	cout<<SimpleFunc(); // 결국 마지막으로 접근한 전역변수 val에서 +7 증가된 val = 107이 출력됨. 
	
	return 0;
}

#endif /* START9 */

