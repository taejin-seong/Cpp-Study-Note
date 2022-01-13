#include "Point.h"
#include "ArrayTemplate.h"


int main(void)
{
	/** int형 정수 저장 **/ 
	BoundCheckArray<int> iarr(5);
	
	for(int i = 0; i < iarr.GetArrLen(); i++)
	{
		iarr[i] = i;
	}
	
	for(int i = 0; i < iarr.GetArrLen(); i++)
	{
		cout<<iarr[i]<<endl;
	}
	
	
	
	/** Point 객체 저장 **/ 
	BoundCheckArray<Point> oarr(3);
	
	oarr[0] = Point(3, 4);
	oarr[1] = Point(5, 6);
	oarr[2] = Point(7, 8);
	
	for (int i = 0; i < oarr.GetArrLen(); i++)
	{
		cout<<oarr[i];
	}
	
	
	
	/** Point 객체의 주소 값 저장 **/ 
	typedef Point* POINT_PTR;
	BoundCheckArray<POINT_PTR>  parr(3);
	
	parr[0] = new Point(30, 40);
	parr[1] = new Point(50, 60);
	parr[2] = new Point(70, 80);
	
	for(int i = 0; i <parr.GetArrLen(); i++)
	{
		cout<<*parr[i];
	}
	
	for(int i = 0; i < parr.GetArrLen(); i++)
	{
		delete parr[i];
	}
	
	return 0;
}
