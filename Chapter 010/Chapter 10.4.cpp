#include <iostream>

//#define START1
//#define START2
//#define START3
#define START4


#ifdef START1

//ConsoleOutput.cpp
namespace mystd
{
	using namespace std; //C언어 표준함수인 printf 함수의 호출을 위해서 삽입 
	
	class ostream
	{
		public:
			void operator<< (char * str)
			{
				printf("%s", str);
			}
			
			void operator<< (char str)
			{
				printf("%c",str);
			}
			
			void operator<< (int num)
			{
				printf("%d", num);
			}
			
			void operator<< (double e)
			{
				printf("%g", e);
			}
			
			void operator<< (ostream& (*fp)(ostream &ostm))
			{
				fp(*this);
			}
	};
	
	
	ostream& endl(ostream &ostm)
	{
		ostm<<'\n';
		fflush(stdout);
		
		return ostm;
	}
	
	
	ostream cout;
}


int main(void)
{

/*	
	mystd::cout<<"Simple String";
	mystd::cout<<mystd::endl;
	mystd::cout<<3.14;
	mystd::cout<<mystd::endl;
	mystd::cout<<123;
	mystd::endl(mystd::cout);
*/

	using mystd::cout;
	using mystd::endl;
	
	cout<<"Simple String";
	cout<<endl;
	cout<<3.14;
	cout<<endl;
	cout<<123;
	endl(cout);	
	
	return 0;
	
}
#endif /* START1 */




#ifdef START2

//IterateConsoleOutput.cpp
namespace mystd
{
	using namespace std; //C언어 표준함수인 printf 함수의 호출을 위해서 삽입 
	
	class ostream
	{
		public:
			ostream& operator<< (char * str)
			{
				printf("%s", str);
				return *this;
			}
			
			ostream& operator<< (char str)
			{
				printf("%c",str);
				return *this;
			}
			
			ostream& operator<< (int num)
			{
				printf("%d", num);
				return *this;
			}
			
			ostream& operator<< (double e)
			{
				printf("%g", e);
				return *this;
			}
			
			ostream& operator<< (ostream& (*fp)(ostream &ostm))
			{
				return fp(*this);
			}
	};
	
	
	ostream& endl(ostream &ostm)
	{
		ostm<<'\n';
		fflush(stdout);
		
		return ostm;
	}
	
	
	ostream cout;
}


int main(void)
{
    using mystd::cout;
    using mystd::endl;
    
    cout<<3.14<<endl<<123<<endl;
    
	return 0;
	
}
#endif /* START2 */





#ifdef START3

using namespace std;

//PointConsoleOutput.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0 , int y = 0) : xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		friend ostream& operator<<(ostream&, const Point&);
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}


int main(void)
{
	Point pos1(1, 3);
	cout<<pos1;
	
	Point pos2(101, 303);
	cout<<pos2;
	
	return 0;
}
#endif /* START3 */






#ifdef START4

using namespace std;

//p436 Question 10-3 NO.1
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0 , int y = 0) : xpos(x), ypos(y)
		{ }
			
		friend ostream& operator<<(ostream&, const Point&);
		friend istream& operator>>(istream&, Point&);
		
};



ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	
	return os;
}



istream& operator>>(istream& is, Point& pos)
{
	is>>pos.xpos>>pos.ypos;
	
	return is;
}


int main(void)
{
	Point pos1;
	cout<<"x, y 좌표 순으로 입력: ";
	cin>>pos1;
	cout<<pos1;
	
	Point pos2;
	cout<<"x, y 좌표 순으로 입력: ";
	cin>>pos2;
	cout<<pos2;
	
	return 0;
}
#endif /* START4 */
