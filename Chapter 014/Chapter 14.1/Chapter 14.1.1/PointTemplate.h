#ifndef POINT_TEMPLATE_H
#define POINT_TEMPLATE_H


#include <iostream>
#include <cstdlib>

using namespace std;


template <typename T> class Point
{
	private:
		T xpos, ypos;
	
	public:
		Point(T x = 0, T y = 0);
		void ShowPosition() const;
};



template <typename T>
Point<T>::Point(T x, T y) :xpos(x), ypos(y)
{ }



template <typename T>
void Point<T>::ShowPosition() const
{
	cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
}

#endif /* POINT_TEMPLATE_H */
