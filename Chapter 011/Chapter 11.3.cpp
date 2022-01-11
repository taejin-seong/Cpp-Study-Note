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

//NewDelteOverloading.cpp
class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }
		
		friend ostream& operator<<(ostream& os, const Point& pos);
		
		
		void* operator new (size_t size) 
		{
			cout<<"operator new : "<<size<<endl;
			void* adr = new char[size];
			
			return adr;
		}
		
		void operator delete (void* adr)
		{
			cout<<"operator delete ()"<<endl;
			
			delete []adr;
		}
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}



int main(void)
{
	Point* ptr = new Point(3, 4);
	cout<<*ptr;
	delete ptr;
	
	return 0;
}
#endif /* START1 */






#ifdef START2

//ArrayNewDeleteOverloading.cpp
class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }
		
		friend ostream& operator<<(ostream& os, const Point& pos);
		
		
		void* operator new (size_t size) 
		{
			cout<<"operator new : "<<size<<endl;
			void* adr = new char[size];
			
			return adr;
		}
		

		void* operator new[] (size_t size) 
		{
			cout<<"operator new[] : "<<size<<endl;
			void* adr = new char[size];
			
			return adr;
		}

		void operator delete (void* adr)
		{
			cout<<"operator delete ()"<<endl;
			
			delete []adr;
		}
		
		
		void operator delete[] (void* adr)
		{
			cout<<"operator delete[] ()"<<endl;
			
			delete []adr;
		}


};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}



int main(void)
{
	Point* ptr = new Point(3, 4);
	Point* arr = new Point[3];
	
	delete ptr;
	delete []arr;
	
	return 0;
}
#endif /* START2 */






#ifdef START3

//PointerOperatorOverloading.cpp
class Number
{
	private:
		int num;
		
	public:
		Number(int n) : num(n) { }
		
		void ShowData()
		{
			cout<<num<<endl;
		}
		
		Number* operator->()
		{
			return this;
		}
		
		Number& operator*()
		{
			return *this;
		}
};



int main(void)
{
	Number num(20);
	num.ShowData();
	
	(*num) = 30;
	num->ShowData();
	(*num).ShowData();
	
	return 0;
}
#endif /* START3 */





#ifdef START4

//SmartPointer.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{
			cout<<"Point 객체 생성"<<endl;
		}
		
		~Point()
		{
			cout<<"Point 객체 소멸"<<endl;
		}
		
		void SetPos(int x, int y)
		{
			xpos = x;
			ypos = y;
		}
		
		friend ostream& operator<<(ostream& os, const Point& pos);
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}



class SmartPtr
{
	private:
		Point* posptr;
		
	public:
		SmartPtr(Point* ptr) : posptr(ptr)
		{ }
		
		Point& operator*() const
		{
			return *posptr;
		}
		
		Point* operator->() const
		{
			return posptr;
		}
		
		~SmartPtr()
		{
			delete posptr;
		}
};




int main(void)
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	
	cout<<*sptr1;
	cout<<*sptr2;
	cout<<*sptr3;
	
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	
	cout<<*sptr1;
	cout<<*sptr2;
	cout<<*sptr3;
	
}
#endif /* START4 */






#ifdef START5

//Functor.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }
		
		Point operator+(const Point& pos) const
		{
			return Point(xpos+pos.xpos, ypos+pos.ypos);
	    }

		friend ostream& operator<<(ostream& os, const Point& pos);
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}



class Adder
{	
	public:
		int operator() (const int& n1, const int& n2)
		{
			return n1 + n2;
		}
		
		double operator()(const double& e1, const double& e2)
		{
			return e1 + e2;
		}
		
		Point operator()(const Point& pos1, const Point& pos2)
		{
			return pos1 + pos2;
		}

};




int main(void)
{
	Adder adder;
	cout<<adder(1, 3)<<endl; 
	cout<<adder(1.5, 3.7)<<endl;
	cout<<adder(Point(3, 4), Point(7, 9));
	
	return 0;
	
}
#endif /* START5 */






#ifdef START6

//SortFuncotr.cpp
class SortRule
{
	public:
		virtual bool operator()(int num1, int num2) const = 0;
};



class AscendingSort : public SortRule
{
	public:
		bool operator()(int num1, int num2) const
		{
			if(num1 > num2)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
};




class DescendingSort : public SortRule
{
	public:
		bool operator() (int num1, int num2) const
		{
			if(num1 < num2)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
};




class DataStorage
{
	private:
		int* arr;
		int idx;
		const int MAX_LEN;
		
	public:
		DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
		{
			arr = new int[MAX_LEN];
		}
		
		
		void AddData(int num)
		{
			if(MAX_LEN <= idx)
			{
				cout<<"더 이상 저장이 불가능합니다."<<endl;
				return;
			}
			
			arr[idx++] = num;
		}
		
		
		void ShowAllData()
		{
			for(int i = 0; i < idx; i++)
			{
				cout<<arr[i]<<' ';
			}
			
			cout<<endl;
		}
		
		
		void SortData(const SortRule& functor)
		{
			for(int i = 0; i < (idx -1); i++)
			{
				for (int j = 0; j < (idx - 1); j++)
				{
					if (functor(arr[j], arr[j+1]))
					{
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
		}
};




int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);
	
	storage.SortData(AscendingSort());
	storage.ShowAllData();
	
	storage.SortData(DescendingSort()); 
	storage.ShowAllData();
	
	return 0;
}
#endif /* START6 */






#ifdef START7

//ConvToObject.cpp
class Number
{
	private:
		int num;
	
	public:
		Number(int n = 0) : num(n)
		{
			cout<<"Number(int n=0)"<<endl;
		}
		
		Number& operator=(const Number& ref)
		{
			cout<<"operator=()"<<endl;
			num = ref.num;
			
			return *this;
		}
		
		void ShowNumber()
		{
			cout<<num<<endl;
		}
};



int main(void)
{
	Number num;
	num = 30;
	num.ShowNumber();
	
	return 0;
}
#endif /* START7 */






#ifdef START8

//ConvToPrimitive.cpp
class Number
{
	private:
		int num;
	
	public:
		Number(int n = 0) : num(n)
		{
			cout<<"Number(int n=0)"<<endl;
		}
		
		Number& operator=(const Number& ref)
		{
			cout<<"operator=()"<<endl;
			num = ref.num;
			
			return *this;
		}
		
		operator int() // 형 변환 연산자의 오버로딩 
		{
			return num;
		}
		
		void ShowNumber()
		{
			cout<<num<<endl;
		}
};



int main(void)
{
	Number num1;
	num1 = 30;
	
	Number num2 = num1 + 30; 
	num2.ShowNumber();
	
	return 0;
}
#endif /* START8 */
