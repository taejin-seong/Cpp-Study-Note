#include <iostream>

#define START5

using namespace std;




#ifdef START1
/*
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
	Car run99 = {"run99", 100, 0};
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
		if(fuelGauge <= 0)
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

#endif /* START2 */





#ifdef START3
/*
*/


//RacingCarEnum.cpp
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
	
	void ShowCarState();			  // 상태정보 출력 
	void Accel();					  // 엑셀, 속도증가 
	void Break();					  // 브레이크, 속도감 

};


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
