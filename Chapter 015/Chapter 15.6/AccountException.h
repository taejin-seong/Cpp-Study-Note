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
		int ExceptionVal; //������ ������ �Ǵ� �ݾ� 
	
	public:
		MinusException(int val) : ExceptionVal(val)
		{ }
		
		void ShowExceptionInfo(void) const
		{
			cout<<"��(��)�ݾ�"<<ExceptionVal<<"�� ��ȿ���� �ʽ��ϴ�!"<<endl;
		}
};


 

class InsuffException
{
	private:
		int Balance;     //���� �ܾ� 
		int RequestVal;  //��� �䱸�� 
	
	public:
		InsuffException(int val, int req) : Balance(val), RequestVal(req)
		{ }
		
		void ShowExceptionInfo(void) const
		{
			cout<<"�ܾ׿��� "<<RequestVal-Balance<<"��(��) �����մϴ�!"<<endl;
		}
		
};

#endif /* ACCOUNT_EXCEPTION_H */
