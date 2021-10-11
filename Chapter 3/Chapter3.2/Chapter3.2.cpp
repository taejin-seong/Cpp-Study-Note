#include <iostream>
#include <cstring>

#define START3

using namespace std;




#ifdef START1
/*
*/


//RacingCarClassBase.cpp
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}


class Car
{
	
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
	
public:
	void InitMembers(const char * ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};


void Car::InitMembers(const char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}


void Car::ShowCarState()
{
	cout<<"소유자ID: "<<gamerID<<endl;
	cout<<"연료량: "<<fuelGauge<<"%"<<endl;
	cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
}


void Car::Accel()
{
	if(fuelGauge <= 0)
	{
		return;
	}
	
	else
	{
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}
	
	if((curSpeed + CAR_CONST::ACC_STEP ) >= CAR_CONST::MAX_SPD )
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	
	curSpeed += CAR_CONST::ACC_STEP;
}


void Car::Break()
{
	if(curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	
	curSpeed -= CAR_CONST::BRK_STEP;
}

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


#endif /* START1 */





#ifdef START2

//p135 Question 3-2

//문제1. 계산기 기능의 Calculator 클래스를 정의해보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며, 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야한다.
// 아래 main 함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다. 단, 멤버변수는 private으로, 멤버함수는 public으로 선언하자. 


class Calculator
{
	
private:
	int numOfAdd;
	int numOfDiv;
	int numOfMin;
	int numOfMul;
	 
public:
	void Init();
	float Add (float num1, float num2); // 더하기 
	float Div (float num1, float num2); // 나누기 
	float Min (float num1, float num2); // 빼기 
	float Mul (float num1, float num2); // 곱하기 
	void ShowOpCount(); // 연산결과 보여주기 
};

void Calculator::Init()
{
	numOfAdd = 0;
	numOfDiv = 0;
	numOfMin = 0;
	numOfMul = 0;
}


float Calculator::Add( float num1, float num2)
{
	numOfAdd++;
	
	return num1 + num2 ;	
}


float Calculator::Div (float num1, float num2)
{
	numOfDiv++;
	
	return num1 / num2 ;
} 


float Calculator::Min (float num1, float num2)
{
	numOfMin++;
	
	return num1 - num2 ;
}


float Calculator::Mul (float num1, float num2)
{
	numOfMul++;
	
	return num1 * num2;
}


void Calculator::ShowOpCount()
{
	cout<<"실행한 더하기 횟수: "<<numOfAdd<<endl;
	cout<<"실행한 나누기 횟수: "<<numOfDiv<<endl;
	cout<<"실행한 빼기 횟수: "<<numOfMin<<endl;
	cout<<"실행한 곱하기 횟수: "<<numOfMul<<endl;
	 
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.8 * 1.2 = "<<cal.Mul(4.9, 1.2)<<endl;
	
	cal.ShowOpCount();
	
	return 0;
	
}

#endif /* START2 */




#ifdef START3

//p135 Question 3-2

//문제2. 문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자. 이 클래스의 두가지 기능은 다음과 같다.
// * 문자열 저장 * 문자열 출력 
// 아래의 main 함수의 실행의 예에 부합하는 Printer 클래스를 정의하되, 이번에도 역시 멤버변수는 private으로, 멤버함수는 public으로 선언하자. 

class Printer
{

private:
	char str[100];

public:
	void SetString(const char *s);
	void ShowString();
};

void Printer::SetString(const char *s)
{
	strcpy(str, s);
}


void Printer::ShowString()
{
	cout<<str<<endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
	
	return 0;
}



#endif /* START2 */




















