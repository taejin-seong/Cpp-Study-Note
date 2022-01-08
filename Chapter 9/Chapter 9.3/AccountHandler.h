/*
 * AcoountHandler.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H


#include "Account.h"
#include "HighCreditAccount.h"



class AccountHandler
{
	private:
		Account* AccountArr[100]; //Account ������ ���� �迭   
		int AccNum ;              //����� Account ��                 

	
	public:
		AccountHandler();	
		
		void ShowMenu(void) const;           //�޴����	
		void MakeAccount(void);              //���°��� �׸���				
		void MakeNormalAccount(void);        //���뿹�ݰ��� ���� 
		void MakeCreditAccount(void);        //�ſ�ŷڰ��� ���� 
		void DepositMoney(void);             //�Ա� 
		void WithDrawMoney(void);            //��� 
		void ShowAllAccountInfo(void) const; //���� ��ȸ
		
		~AccountHandler();
		

};

#endif /* ACCOUNT_HANDLER_H */
