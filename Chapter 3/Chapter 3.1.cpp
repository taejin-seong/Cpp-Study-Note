#include <iostream>

#define START5

using namespace std;




#ifdef START1
/*
1.구조체는 연관 있는 데이터를 묶을 수 있는 법적 장치...
2.C++에서는 별도의 typedef 선언 없이도 다음과 같이 변수를 선언할 수 있다.

ex)
	Car basicCar; 
*/


//RacingCar.cpp
#define ID_LEN		20
#define MAX_SPD 	200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gameID[ID_LEN]; // 소유자ID
	int fuelGauge;       // 연료량 
	int curSpeed;        // 현재속도 
};

void ShowCarState(const Car &car)
{
	cout<<"소유자ID: "<<car.gameID<<endl;
	cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
	cout<<"현재속도: "<<car.curSpeed<<"km/s"<<endl<<endl; 
}

void Accel(Car &car)
{
	if(car.fuelGauge <= 0)
	{
		return;
	}
	else
	{
		car.fuelGauge -= FUEL_STEP;
	}
	
	if(car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}
	
	car.curSpeed += ACC_STEP;
}


void Break(Car &car)
{
	if(car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main(void)
{
	Car run99 = {"run99", 100, 0}; // C++에서는 별도의 typedef 선언 없이도 다음과 같이 변수를 선언할 수 있다.
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);
	
	Car sped77 = {"sped77", 100, 0};
	Accel(sped77);
	Break(sped77);
	ShowCarState(sped77);
	
	return 0;
	
}

#endif /* START1 */








#ifdef START2
/*
1.C++에서는 구조체 안에 함수를 삽입하는 것을 허용
2.함수가 구조체 내에 삽입되면서 구조체 내에 선언된 변수에 직접저븐이 가능해짐. 
*/


//RacingCarFuncAdd.cpp
#define ID_LEN		20
#define MAX_SPD 	200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];  // 소유자 ID
	int fuelGauge;  	   // 연료량
	int curSpeed;          // 현재속도 
	
	void ShowCarState()
	{
		cout<<"소유자ID: "<<gamerID<<endl;
		cout<<"연료량: "<<fuelGauge<<"%"<<endl;
		cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
	} 
	
	
	void Accel()
	{
		if(fuelGauge <= 0) // 구조체안에 함수가 삽입되었기에 멤버 연산자 없이 구조체 멤버에 직접접근이 가능 
		{
			return;
		}
		
		else
		{
			fuelGauge -= FUEL_STEP;
		}
		
		if(curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}
		
		curSpeed += ACC_STEP;
	}
	
	
	void Break()
	{
		if(curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		
		curSpeed -= BRK_STEP ;
	}

};

int main(void)
{
	Car run99 = {"run99", 100, 0};
	run99.Accel();  // 구조체 안에 함수가 들어갔으므로 멤버 연산자로 접근 
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	
	Car sped77 = {"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	
	return 0;
	
}

#endif /* START2 */





#ifdef START3
/*
1. 열거형 enum을 이용해서 구조체 내에서만 유효한 상수를 정의할 수 있음.
2. 이름공간을 이용해서 상수가 사용되는 영역을 명시하는 것도 또 다른 방법이 될 수가 있음. ~ 가독성이 좋아짐 
*/


//RacingCarEnum.cpp
namespace CAR_CONST  // 이름공간을 통해 상수가 사용되는 영역을 명시 
{
	enum
	{
		ID_LEN    =  20,
	    MAX_SPD   =  200,
	    FUEL_STEP =	 2,
		ACC_STEP  =	 10,
		BRK_STEP  =  10
	};
}


struct Car
{
	char gamerID[CAR_CONST::ID_LEN];  // 소유자 ID  //  이름공간 CAR_CONST에 선언딘 ID_LEN 
	int fuelGauge;                    // 연료량 
	int curSpeed;                     // 현재속도 
	
	void ShowCarState()
	{
		cout<<"소유자ID: "<<gamerID<<endl;
		cout<<"연료량: "<<fuelGauge<<"%"<<endl;
		cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
	} 
	
	
	void Accel()
	{
		if(fuelGauge <= 0)
		{
			return;
		}
		
		else
		{
			fuelGauge -= CAR_CONST::FUEL_STEP;
		}
		
		if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
		{
			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}
		
		curSpeed += CAR_CONST::ACC_STEP;
	}
	
	
	void Break()
	{
		if(curSpeed < CAR_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		
		curSpeed -= CAR_CONST::BRK_STEP ;
	}

};

int main(void)
{
	Car run99 = {"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	
	Car sped77 = {"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	
	return 0;
	
}

#endif /* START3 */





#ifdef START4
/*
1.구조체 밖으로 함수를 빼낼 수 있다. 
2. 함수의 원형선언을 구조체 안에 두고, 함수의 정의를 구조체 밖으로 빼내면 됨. 
*/


//RacingCarOuterFuncAdd.cpp
namespace CAR_CONST
{
	enum
	{
		ID_LEN    =  20,
	    MAX_SPD   =  200,
	    FUEL_STEP =	 2,
		ACC_STEP  =	 10,
		BRK_STEP  =  10
	};
}


struct Car
{
	char gamerID[CAR_CONST::ID_LEN];  // 소유자 ID
	int fuelGauge;  	              // 연료량
	int curSpeed;                     // 현재속도 
	
	void ShowCarState();			  // 상태정보 출력    /*  
	void Accel();					  // 엑셀, 속도증가        함수의 원형 선언 
	void Break();					  // 브레이크, 속도감                          */

};


void Car::ShowCarState()
{
	cout<<"소유자ID: "<<gamerID<<endl;
	cout<<"연료량: "<<fuelGauge<<"%"<<endl;
	cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
} 
	
// Car라는 구조체 안에 정의된 함수 Accel...	
void Car::Accel()  // 함수의 정의를 구조체 밖으로 뺴냄. ( 구조체 안에 선언된 함수의 정의 ) 
{
	if(fuelGauge <= 0)
	{
		return;
	}
		
	else
	{
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}
		
	if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
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
		
	curSpeed -= CAR_CONST::BRK_STEP ;
}


int main(void)
{
	Car run99 = {"run99", 100, 0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	
	Car sped77 = {"sped77", 100, 0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	
	return 0;
	
}

#endif /* START4 */


/*
1. 구조체 안에 함수가 정의되어있으면 함수를 인라인으로 처리한다.
2. 함수를 구조체 밖으로 뺴내면 인라인의 의미가 사라짐. 따라서 의미를 그대로 유지하려면 inline을 이용해서 인라인 처리를 명시적으로 지시해야한다. 

ex)
	inline void Car::ShowCarState()
	{
    	......
	}

*/


/*
 ****** 위에서 정의한 구조체를 가리켜 그냥 '클래스'라고 표현해도 틀리지 않는다. ****** 
*/


#ifdef START5

//p114 Question 3-1

//문제. 책 참 조 

struct Point
{
	int xpos;
	int ypos;
	
	void MovePos(int x, int y);
	void AddPoint(const Point &pos);
	void ShowPosition(); 
	
};

void Point::MovePos(int x, int y)
{
	xpos += x;
	ypos += y;
}


void Point::AddPoint(const Point &pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;
	
}


void Point::ShowPosition()
{
	cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
	
} 


int main(void)
{
	Point pos1 = {12, 4};
	Point pos2 = {20, 30};
	
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();  // [5, 14] 출력
	
	pos1.AddPoint(pos2);
	pos1.ShowPosition();  // [25, 44] 출력
	
	return 0; 
}
#endif /* START5 */
