/*
 * AcoountArray.h
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 */
 
 
#ifndef ACCOUNT_ARRAY_H
#define ACCOUNT_ARRAY_H


#include "Account.h"


typedef Account* ACCOUNT_PTR; 


class BoundCheckPointPtrArray
{
	private:
		ACCOUNT_PTR* arr;  
		int arrlen;
		
		BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
		BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }
	
	public:
		BoundCheckPointPtrArray(int len = 100);
		ACCOUNT_PTR& operator[] (int idx);
		ACCOUNT_PTR operator[] (int idx) const;	
		int GetArrLen() const;
	
		~BoundCheckPointPtrArray();
};

#endif /* ACCOUNT_ARRAY_H */
