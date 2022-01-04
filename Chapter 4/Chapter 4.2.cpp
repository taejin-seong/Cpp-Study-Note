#include <iostream>

//#define START1
//#define START2
#define START3

using namespace std;




#ifdef START1

//Encaps1.cpp
class SinivelCap
{
	public:
		void Take() const
		{
			cout<<"Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù."<<endl;
		}
};

class SneezeCap
{
	public:
		void Take() const
		{
			cout<<"ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù."<<endl;
		}
};

class SnuffleCap
{
	public: 
		void Take() const
		{
			cout<<"ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù."<<endl;
		}
};


class ColdPatient
{
	public:
		void TakeSinivelCap(const SinivelCap &cap) const
		{
			cap.Take();
		}
		
		void TakeSneezeCap(const SneezeCap &cap) const
		{
			cap.Take();
		}
		
		void TakeSnuffleCap(const SnuffleCap &cap) const
		{
			cap.Take();
		}
};

int main (void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;
	
	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	
	return 0;
	
}

#endif /* START1 */



#ifdef START2

//Encaps2.cpp
class SinivelCap
{
	public:
		void Take() const
		{
			cout<<"Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù."<<endl;
		}
};

class SneezeCap
{
	public:
		void Take() const
		{
			cout<<"ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù."<<endl;
		}
};

class SnuffleCap
{
	public: 
		void Take() const
		{
			cout<<"ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù."<<endl;
		}
};

class CONTAC600
{
	private:
		SinivelCap sin;
		SneezeCap sne;
		SnuffleCap snu;
	
	public:
		void Take() const
		{
			sin.Take();
			sne.Take();
			snu.Take();
		}
};

class ColdPatient
{
	public:
		void TakeCONTAC600 (const CONTAC600 &cap) const
		{
			cap.Take();
		}
};

int main (void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	
	sufferer.TakeCONTAC600(cap);
		
	return 0;
	
}

#endif /* START2 */




#ifdef START3

//p166 Question 4-2

class Point
{
	private:
		int xpos, ypos;
	
	public:
		void Init(int x, int y)
		{
			xpos = x;
			ypos = y;
		}
		
		void ShowPointInfo() const
		{ 
			cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;	
		}
};

class Circle
{
	private:
		Point po;
		int xpos, ypos, radius;
	
	public:
		void InitCircle(int x, int y, int r) 
		{
			po.Init(x,y);
			radius = r;
			
		}
		
		void ShowCircleInfo() const
		{
			cout<<"radius: "<<radius<<endl;
			po.ShowPointInfo();
			
		}
					
};


class Ring
{
	private:
		Circle inner_cir;
		Circle outter_cir;
		
	public:
		void Init(int x1, int y1, int r1, int x2, int y2, int r2) 
		{
			inner_cir.InitCircle(x1,y1,r1);
			outter_cir.InitCircle(x2,y2,r2);
		}
		
		void ShowRingInfo() const
		{
			cout<<"Inner Circle Info... "<<endl;
			inner_cir.ShowCircleInfo();
			cout<<"Outter Circle Info... "<<endl;
			outter_cir.ShowCircleInfo();
			
			
		}
};

int main(void)
{
	Ring ring;
	ring.Init(1,1,4,2,2,9);
	ring.ShowRingInfo();
	
	return 0;
}

 
#endif /* START3 */