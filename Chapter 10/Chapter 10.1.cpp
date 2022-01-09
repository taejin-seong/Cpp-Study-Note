#include <iostream>

//#define START1
//#define START2
#define START4


using namespace std;


#ifdef START1

//FirstOperationOverloading.cpp
class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) :xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		Point operator+(const Point &ref) //operator+��� �̸��� �Լ� 
		{
			Point pos(xpos+ref.xpos, ypos+ref.ypos);
			
			return pos;
		}
};



int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
//               ����Լ��� ȣ���� ��ü.�Լ��� �̸�(�Լ��� ��������); 
	Point pos3 = pos1.operator+(pos2); //����Լ��� �����ε� �� ��� 
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	
	return 0;
 }
 #endif /* START1 */ 
 
 
 
 
 #ifdef START2
 
 //OverloadingOperation.cpp
 class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) :xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		Point operator+(const Point &ref) //operator+��� �̸��� �Լ� 
		{
			Point pos(xpos+ref.xpos, ypos+ref.ypos);
			
			return pos;
		}
};


int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1+pos2;
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	
	return 0;
 }
 #endif /* START2 */
 
 
 
 #ifdef START3
 
 //GetFunctionOverloading.cpp
 class Point
 {
 	private:
 		int xpos, ypos;
 	
 	public:
 		Point(int x = 0, int y =0) : xpos(x), ypos(y)
 		{ }
 		
 		void ShowPosition() const
 		{
 			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		friend Point operator+(const Point &pos1, const Point &pos2);
 };
 

//�����Լ��� �����ε��� ��� 
Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
	
	return pos;
}


int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;
//	Point pos3 = operator+(pos1, pos2); //�����Լ��� �����ε� �� ��� 
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	
	return 0;
}
#endif /* START3 */ 
 
 


 
#ifdef START4

//p409 Question 10-1 NO.1
class Point
{
	private:
		int xpos, ypos;
		
	public:
		Point(int x = 0, int y = 0) :xpos(x), ypos(y)
		{ }
		
		void ShowPosition() const
		{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		
		Point& operator+=(const Point &ref)
		{
			xpos += ref.xpos;
			ypos += ref.ypos;
			
			return *this; 
		}
		
		Point& operator-=(const Point &ref)
		{
			xpos -= ref.xpos;
			ypos -= ref.ypos;
			
			return *this; 
		} 
				
		friend Point operator-(const Point &, const Point &);
		friend bool operator==(const Point &, const Point &);
		friend bool operator!=(const Point &, const Point &);
		
};



Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	
	return pos; //������ ����� ���� Point ��ü ��ȯ 
}



bool operator==(const Point &pos1, const Point &pos2)
{
	if((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos))
	{
		return true;
	}
	
	else
	{
		return false;
	}
}



bool operator!=(const Point &pos1, const Point &pos2)
{
	return !(pos1==pos2); //�����ε��� == �����ڸ� ȣ�� 
	
}
		
		


int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3(20, 30);
	
	(pos1-pos2).ShowPosition(); //��ü�� ��ȯ�ϹǷ� �Լ�ȣ�� ���� 
	(pos2+=pos3).ShowPosition(); //��ȯ���� �������̹Ƿ� �Լ�ȣ�� ���� 
	
	if(pos2==pos3)
	{
		cout<<"equal"<<endl;
	}
	else
	{
		cout<<"not equal"<<endl;
	}
	
	
	(pos2-=pos3).ShowPosition(); //��ȯ���� �������̹Ƿ� �Լ�ȣ�� ���� 
	
	
	if(pos2!=pos3)
	{
		cout<<"not equal"<<endl;
	}
	
	else
	{
		cout<<"equal"<<endl;
	}
	
	return 0;
}
#endif /* START4 */
