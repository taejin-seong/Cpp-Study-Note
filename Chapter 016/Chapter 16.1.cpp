#include <iostream>


//#define START1
//#define START2
//#define START3
//#define START4
//#define START5 
//#define START6
//#define START7
#define START8


using namespace std;


#ifdef START1

//PowerfullCasting.cpp
class Car
{
	private:
		int fuelGauge;
	
	public:
		Car(int fuel) : fuelGauge(fuel)
		{ }
		
		void ShowCarState()
		{
			cout<<"잔여 연료량: "<<fuelGauge<<endl;
		}
};




class Truck : public Car
{
	private:
		int freightWeight;
	
	public:
		Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
		{ }
		
		void ShowTruckState()
		{
			ShowCarState();
			cout<<"화물의 무계: "<<freightWeight<<endl;
		}
};




int main(void)
{
	Car* pcar1 = new Truck(80, 200); //문제 없어보이는 형 변환 그러나 
	Truck* ptruck1 = (Truck*)pcar1;  //기초 클래스의 포인터형을 유도 클래스의 포인터 형으로 변환하는 것은 일반적인 연산 x 
    ptruck1->ShowTruckState();
    
	cout<<endl;;
	
	Car* pcar2 = new Car(120); //문제가 바로 보이는 형 변환 
	Truck* ptruck2 = (Truck*)pcar2;
	ptruck2->ShowTruckState();
	
	return 0;
}
#endif /* START1 */






#ifdef START2

//DynamicCasting.cpp
class Car
{
	private:
		int fuelGauge;
	
	public:
		Car(int fuel) : fuelGauge(fuel)
		{ }
		
		void ShowCarState()
		{
			cout<<"잔여 연료량: "<<fuelGauge<<endl;
		}
};




class Truck : public Car
{
	private:
		int freightWeight;
	
	public:
		Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
		{ }
		
		void ShowTruckState()
		{
			ShowCarState();
			cout<<"화물의 무계: "<<freightWeight<<endl;
		}
};




int main(void)
{
	
//	Car* pcar1 = new Truck(8, 200);
//	Truck* ptruck1 = dynamic_cast<Truck*>(pcar1); //컴파일 에러 

//	Car* pcar2 = new Car(120);
//	Truck* ptruck2 = dynamic_cast<Truck*>(pcar2); //컴파일 에러 

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);     //컴파일 OK! 
	
	return 0;

}
#endif /* START2 */





#ifdef START3

//StaticCasting.cpp
class Car
{
	private:
		int fuelGauge;
	
	public:
		Car(int fuel) : fuelGauge(fuel)
		{ }
		
		void ShowCarState()
		{
			cout<<"잔여 연료량: "<<fuelGauge<<endl;
		}
};




class Truck : public Car
{
	private:
		int freightWeight;
	
	public:
		Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
		{ }
		
		void ShowTruckState()
		{
			ShowCarState();
			cout<<"화물의 무계: "<<freightWeight<<endl;
		}
};




int main(void)
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1); //컴파일 OK! 
	ptruck1->ShowTruckState();
	
	cout<< endl;
	
	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2); //컴파일 OK! 그러나.. 
	ptruck2->ShowTruckState();
	
	return 0;
}
#endif /* START3 */





#ifdef START4

//ConstCasting.cpp
void ShowString(char* str)
{
	cout<<str<<endl;
}


void ShowAddResult(int& n1, int& n2)
{
	cout<<n1+n2<<endl;
}



int main(void)
{
	const char* name = "Lee Sung Ju";
	ShowString(const_cast<char*>(name));
	
	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
	
	return 0; 
}
#endif /* START4 */





#ifdef START5

//ReinterpretCasting.cpp
int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);
	
	
	for(int i = 0; i < sizeof(num); i++)
	{
		cout<<static_cast<int>(*(ptr+1))<<endl;
	}
	
	return 0;
}
#endif /* START5 */





#ifdef START6

//PolymorphicDynamicCasting.cpp
class SoSimple
{
	public:
		virtual void ShowSimpleInfo()
		{
			cout<<"SoSimple Base Class"<<endl;
		}
};


class SoComplex : public SoSimple
{
	public:
		void ShowSimpleInfo()
		{
			cout<<"SoComplex Derived Class"<<endl;
		}
};


int main(void)
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	
	return 0;
}
#endif /* START6 */





#ifdef START7

//PolymorphicStableCasting.cpp
class SoSimple
{
	public:
		virtual void ShowSimpleInfo()
		{
			cout<<"SoSimple Base Class"<<endl;
		}
};


class SoComplex : public SoSimple
{
	public:
		void ShowSimpleInfo()
		{
			cout<<"SoComplex Derived Class"<<endl;
		}
};


int main(void)
{
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	
	if (comPtr == NULL)
	{
		cout<<"형 변환 실패"<<endl;
	}
	
	else
	{
		comPtr->ShowSimpleInfo();
	}
	
	return 0;
}
#endif /* START7 */





#ifdef START8

//DynamicBadCastRef.cpp
class SoSimple
{
	public:
		virtual void ShowSimpleInfo()
		{
			cout<<"SoSimple Base Calss"<<endl;
		}
};


class SoComplex : public SoSimple
{
	public:
		void ShowSimpleInfo()
		{
			cout<<"SoComplex Derived Class"<<endl;
		}
};


int main(void)
{
	SoSimple simObj1;
	SoSimple& ref = simObj1;
	
	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
		comRef.ShowSimpleInfo();
	}
	
	catch(bad_exception expt) //bad_cast
	{
		cout<<expt.what()<<endl;
	}
	
	return 0;
}
#endif /* START8 */
