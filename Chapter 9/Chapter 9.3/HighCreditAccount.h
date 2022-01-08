/*
 * HighCreditAccount.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef HIGH_CREDIT_ACCOUNT_H
#define HIGH_CREDIT_ACCOUNT_H 


#include "NormalAccount.h"


///½Å¿ë½Å·Ú°èÁÂ 
class HighCreditAccount : public NormalAccount  
{
	private:
		int PlusRate;

	public:
		HighCreditAccount(int id, int money, char* name, int rate, int plus) 
		                 : NormalAccount(id, money, name, rate), PlusRate(plus) { } 
		
		
		virtual void Deposit(int money)
		{
			NormalAccount::Deposit(money);
			Account::Deposit(money * (PlusRate / 100.0));
		}			
	
};

#endif /* HIGH_CREDIT_ACCOUNT_H */
