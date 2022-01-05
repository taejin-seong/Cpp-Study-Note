#include <iostream>
#include <cstring>

//#define START1
#define START2			
		

using namespace std;





#ifdef START1

//MyFriendClass.cpp
class Girl;

class Boy
{
	private:
		int height;
		friend class Girl;
		
	public:
		Boy(int len) : height(len){}
		
		void ShowYourFriendInfo(Girl &frn);
};


class Girl
{
	private:
		char phNum[20];
	
	public:
		Girl(char* num)
		{
			strcpy(phNum, num);
		}
		
		void ShowYourFriendInfo(Boy &frn);
		
		friend class Boy;
};


void Boy::ShowYourFriendInfo(Girl &frn)
{
	cout<<"Her phone number: "<<frn.phNum<<endl;

}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout<<"His height: "<<frn.height<<endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	
	return 0;
}

#endif /* START1 */




#ifdef START2

//MyFriendFunction.cpp
class Point;

class PointOP
{
	private:
		int opcnt;
	
	public:
		PointOP() :opcnt(0) {}
		
		Point PointAdd(const Point&, const Point&);
		
		Point PointSub(const Point&, const Point&);
		
		~PointOP()
		{
			cout<<"Operation times: "<<opcnt<<endl;
		}
		
};


class Point
{
	private:
		int x;
		int y;
	
	public:
		Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) {}
		
		friend Point PointOP::PointAdd(const Point&, const Point&);
		
		friend Point PointOP::PointSub(const Point&, const Point&);
		
		friend void ShowPointPos(const Point&);	

};


Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;
	
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	
	return 0;
}


void ShowPointPos(const Point& pos)
{
	cout<<"x: "<<pos.x<<", ";
	cout<<"y: "<<pos.y<<endl;
}
#endif /* START2 */