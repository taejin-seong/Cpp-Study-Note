/*
 * AcoountHandler.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H


#include "AccountArray.h"
#include "HighCreditAccount.h"



class AccountHandler
{
	private:
		BoundCheckPointPtrArray AccountArr;  //Acoount 배열 클래스  
		int AccNum ;                         //저장된 Account 수                 

	
	public:
		AccountHandler();			
		void ShowMenu(void) const;           //메뉴출력	
		void MakeAccount(void);              //계좌개설 항목선택				
		void DepositMoney(void);             //입금 
		void WithDrawMoney(void);            //출금 
		void ShowAllAccountInfo(void) const; //계좌 조회
		~AccountHandler();
	
	protected:
		void MakeNormalAccount(void);        //보통예금계좌 개설 
		void MakeCreditAccount(void);        //신용신뢰계좌 개설 
	
};

#endif /* ACCOUNT_HANDLER_H */
