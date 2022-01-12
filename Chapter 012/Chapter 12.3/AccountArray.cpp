/*
 * AcoountArray.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.9
 */
 
 
#include "AccountArray.h"
 
 
BoundCheckPointPtrArray::BoundCheckPointPtrArray (int len) : arrlen(len)
{
		arr = new ACCOUNT_PTR[len];
}
		


ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout<<"Array index out of bound excpetion"<<endl;
		exit(1);
	}
		
	return arr[idx];
}
		

	
ACCOUNT_PTR BoundCheckPointPtrArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout<<"Array index out of bound excpetion"<<endl;
		exit(1);
	}
			
	return arr[idx];			
}


		 
int BoundCheckPointPtrArray::GetArrLen() const
{
	return arrlen;
}
		

		
BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
	delete []arr;
}
