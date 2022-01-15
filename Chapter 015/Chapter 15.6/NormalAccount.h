/*
 * NormalAccount.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef NORMAL_ACCOUNT_H 
#define NORMAL_ACCOUNT_H 


#include "Account.h"

 
class NormalAccount : public Account  
{
	private:
		int InterestRate;
	
	public:
		NormalAccount(int id, int money, String name, int rate) : Account(id, money, name), InterestRate(rate) 
		{ } 
	
		
		virtual void Deposit(int money)
		{
			if (money < 0)
			{
				throw MinusException(money);
			}
			
			Account::Deposit(money);
			Account::Deposit(money* (InterestRate / 100.0));
		}		
};

#endif /* NORMAL_ACCOUNT_H */
