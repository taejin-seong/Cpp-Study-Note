#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
	private:
		Point upLeft;
		Point lowRight;
	
	public:
		bool InitMembers(const Point &u1, const Point &lr);
		void ShowRecInfo() const;
};
#endif