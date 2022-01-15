/*
 * AcoountException.h
 *
 *  Created on: Jan 15, 2022
 *      Author: Tae Jin
 */


#ifndef ACCOUNT_EXCEPTION_H
#define ACCOUNT_EXCEPTION_H


#include "BankingCommonDecl.h"


class MinusException
{
	private:
		int ExceptionVal; //예외의 원인이 되는 금액 
	
	public:
		MinusException(int val) : ExceptionVal(val)
		{ }
		
		void ShowExceptionInfo(void) const
		{
			cout<<"입(출)금액"<<ExceptionVal<<"은 유효하지 않습니다!"<<endl;
		}
};


 

class InsuffException
{
	private:
		int Balance;     //현재 잔액 
		int RequestVal;  //출금 요구액 
	
	public:
		InsuffException(int val, int req) : Balance(val), RequestVal(req)
		{ }
		
		void ShowExceptionInfo(void) const
		{
			cout<<"잔액에서 "<<RequestVal-Balance<<"가(이) 부족합니다!"<<endl;
		}
		
};

#endif /* ACCOUNT_EXCEPTION_H */
