#include <iostream>

//#define START1
//#define START2
#define START3


using namespace std;



#ifdef START1

//OneOpndOverloading.cpp
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
		
		Point& operator++() //++�����ڰ� ����Լ��� ���·� �����ε���. 
		{
			xpos +=1;
			ypos +=1;
			
			return *this; //������ ��ȯ 
		}
		
		friend Point& operator--(Point &ref);
};


Point& operator--(Point &ref) //--�����ڰ� �����Լ��� ���·� �����ε��� 
{
	ref.xpos-=1;
	ref.ypos-=1;
	
	return ref; //��ü��ȯ 
}


int main(void)
{
	Point pos(1, 2);
	
	++pos; //++�����ڴ� ����Լ��� ���·� �����ε� �Ǿ����Ƿ�, pos.operator++();�� �ؼ���
	pos.ShowPosition();
	
	--pos; //--�����ڴ� �����Լ��� ���·� �����ε� �Ǿ����Ƿ�, pos.operator--(pos);�� �ؼ��� 
	pos.ShowPosition();
	
	++(++pos);
	pos.ShowPosition();
	
	--(--pos);
	pos.ShowPosition();
	
	return 0;
}

#endif /* START1 */





#ifdef START2

//p418 Question 10-2 NO.1
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
		
		Point operator-()
		{
			Point  pos(-xpos, -ypos);
			
			return pos;
		}
		
		friend Point operator~(const Point &);
		
};



Point operator~(const Point &ref)
{
	Point pos(ref.ypos, ref.xpos);
	
	return pos;
}



int main(void)
{
	Point pos1(-10, 3);
	Point pos2 = -pos1;
	pos2.ShowPosition();
	
	(~pos2).ShowPosition();
	pos2.ShowPosition();
	
	return 0;
}
#endif /* START2 */





#ifdef START3

//PostOpndOverloading.cpp
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
		
		Point& operator++() //�������� 
		{
			xpos += 1;
			ypos += 1;
			
			return *this; 
		}
		
		const Point operator++(int) //��������
		{
			const Point retobj(xpos, ypos); //const Point retobj(*this);
			xpos += 1;
			ypos += 1;
			
			return retobj;
		}
		
		friend Point& operator--(Point &ref);
		friend const Point operator--(Point &ref, int);
		
};



Point& operator--(Point &ref) //�������� 
{
	ref.xpos-=1;
	ref.ypos-=1;
	
	return ref;
}




const Point operator--(Point &ref, int) //�������� 
{
	const Point retobj(ref); //const��ü
	ref.xpos -= 1;
	ref.ypos -= 1;
	
	return retobj; 
}



int main(void)
{
	Point pos(3, 5);
	Point cpy;
	
	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();
	
	cpy = pos++;
	cpy.ShowPosition();
	cpy.ShowPosition();
	
	return 0;
}

#endif /* START3 */
