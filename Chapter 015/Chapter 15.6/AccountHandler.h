/*
 * AcoountHandler.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H


#include "BoundCheckArray.h"
#include "HighCreditAccount.h"


class AccountHandler
{
	private:
		BoundCheckArray<Account*>  AccountArr;  //Account ��ü �ּҰ� ����  
		int AccNum ;                            //����� Account ��                 

	
	public:
		AccountHandler();			
		void ShowMenu(void) const;           //�޴����	
		void MakeAccount(void);              //���°��� �׸���				
		void DepositMoney(void);             //�Ա� 
		void WithDrawMoney(void);            //��� 
		void ShowAllAccountInfo(void) const; //���� ��ȸ
		~AccountHandler();
	
	protected:
		void MakeNormalAccount(void);        //���뿹�ݰ��� ���� 
		void MakeCreditAccount(void);        //�ſ�ŷڰ��� ���� 
	
};

#endif /* ACCOUNT_HANDLER_H */
