#include <iostream>

//#define START1
#define START2


using namespace std;



#ifdef START1

//PointMultipleOperation.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y = 0) : xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		
		Point operator*(int times) //°ö¼À ¿¬»êÀÚ ¿À¹ö·Îµù 
		{
			Point pos(xpos*times, ypos*times);
			
			return pos;	
		}
};



int main(void)
{
	Point pos(1, 2);
	Point cpy;
	
	cpy = pos*3;
	cpy.ShowPosition();
	
	spy = pos*3*2;
	cpy.ShowPosition();
	
	return 0;	
}
#endif /* START1 */





#ifdef START2

//CommuMultipleOperation.cpp
class Point
{
	private:
		int xpos, ypos;
	
	public:
		Point(int x = 0, int y =0) :xpos(x), ypos(y)
		{ }
		
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		
		Point operator*(int times)
		{
			Point pos(xpos*times, ypos*times);
			return pos;
		}
		
		friend Point operator*(int times, Point& ref);
};




Point operator*(int times, Point& ref)
{
	return ref*times;
}



int main(void)
{
	Point pos(1,2);
	Point cpy;
	
	cpy = 3*pos;
	cpy.ShowPosition();
	
	cpy = 2*pos*3;
	cpy.ShowPosition();
	
	return 0;
}
#endif /* START2 */ 
