#include <iostream>
#include <cstring>

#define START3

using namespace std;




#ifdef START1
/*
1. struct�� ����ؼ� class�� ����ϸ�, ����ü�� �ƴ� Ŭ������ �ȴ�.

2. Ŭ������ �����ϴ� �������� ������ ���� �� �Լ��� ���� �������� ������ �����ؾ��Ѵ�.

------------------------���� ������------------------------ 

* public    : ��𼭵� ���� ��� 
* protcted  : ��Ӱ��迡 �������� ��, ���� Ŭ���������� ���� ���
* private   : Ŭ���� �� (Ŭ���� ���� ���ǵ� �Լ�) ������ ���� ���   

------------------------------------------------------------

3. struct�� �������� �� ��� ����� public���� ����Ʈ �ν� 
4. class�� �������� �� ��� ����� private���� ����Ʈ �ν�          ~ Ŭ���� �� public �Լ����� private ���� �ʱ�ȭ ����.

* ����ü�� Ŭ������ �������� �������� ������ �����ϰ�, �� �ǹ̵� �����ϴ�. �ٸ� ���������� ����Ʈ �νĸ� �ٸ� �� 

5. * ��ü(object) = ����+���
   * Ŭ������ �����ϴ� ���� (Ŭ���� ���� ����� ����) = ��� ����
   * Ŭ������ �����ϴ� �Լ� (Ŭ���� ���� ���ǵ� �Լ�) = ��� �Լ�
   
6. ��� ������ private����... ��� �Լ��� public����...   
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


class Car  // Ŭ���� ���� 
{
	
private:  // ���ݺ��� private  
	char gamerID[CAR_CONST::ID_LEN];  /* �ܺο��� ���� �Ұ� */  
	int fuelGauge;					  	
	int curSpeed;                      // -> ��� ���� 
	 
public:  // ���ݺ��� public                      
	void InitMembers(const char * ID, int fuel);  /* ��𼭵� ���� ��� */ 
	void ShowCarState();
	void Accel();
	void Break();                      // -> ��� �Լ�
	 
};


void Car::InitMembers(const char * ID, int fuel)  // Ŭ���� �ȿ� ����� ������ �ʱ�ȭ�� �������� ���ǵ� �Լ�. 
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}


void Car::ShowCarState()
{
	cout<<"������ID: "<<gamerID<<endl;
	cout<<"���ᷮ: "<<fuelGauge<<"%"<<endl;
	cout<<"����ӵ�: "<<curSpeed<<"km/s"<<endl<<endl;
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
	Car run99; // ��ü ����. ���� + ��� 
	 
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

//����1. ���� ����� Calculator Ŭ������ �����غ���. �⺻������ ���ϴ� ����� ����, ����, ���� �׸��� �������̸�, ������ �� ������ ��� ������ �� �� �����ߴ��� ��ϵǾ���Ѵ�.
// �Ʒ� main �Լ��� ������ ���� �����ϴ� Calculator Ŭ������ �����ϸ� �ȴ�. ��, ��������� private����, ����Լ��� public���� ��������. 


class Calculator
{
	
private:
	int numOfAdd;
	int numOfDiv;
	int numOfMin;
	int numOfMul;
	 
public:
	void Init();
	float Add (float num1, float num2); // ���ϱ� 
	float Div (float num1, float num2); // ������ 
	float Min (float num1, float num2); // ���� 
	float Mul (float num1, float num2); // ���ϱ� 
	void ShowOpCount(); // ������ �����ֱ� 
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
	cout<<"������ ���ϱ� Ƚ��: "<<numOfAdd<<endl;
	cout<<"������ ������ Ƚ��: "<<numOfDiv<<endl;
	cout<<"������ ���� Ƚ��: "<<numOfMin<<endl;
	cout<<"������ ���ϱ� Ƚ��: "<<numOfMul<<endl;
	 
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

//����2. ���ڿ� ������ ���ο� �����ϴ� Printer��� �̸��� Ŭ������ ����������. �� Ŭ������ �ΰ��� ����� ������ ����.
// * ���ڿ� ���� * ���ڿ� ��� 
// �Ʒ��� main �Լ��� ������ ���� �����ϴ� Printer Ŭ������ �����ϵ�, �̹����� ���� ��������� private����, ����Լ��� public���� ��������. 

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




















