/*
 * NormalAccount.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef NORMAL_ACCOUNT_H 
#define NORMAL_ACCOUNT_H 


#include "Account.h"

 
//보통예금계좌 
class NormalAccount : public Account  
{
	private:
		int InterestRate;
	
	public:
		NormalAccount(int id, int money, char* name, int rate) 
		             : Account(id, money, name), InterestRate(rate) { } 
	
	
		
		virtual void Deposit(int money)
		{
			Account::Deposit(money);
			Account::Deposit(money* (InterestRate / 100.0));
		}		
};

#endif /* NORMAL_ACCOUNT_H */
