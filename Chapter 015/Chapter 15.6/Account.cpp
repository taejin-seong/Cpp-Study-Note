/*
 * Acoount.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.12
 */


#include "Account.h"



Account::Account(int id, int moeny, String name) :AccID(id), Balance(moeny) 
{
	ClientName = name;
}




int Account::GetID(void) const 
{
	return AccID;
}



		
void Account::Deposit(int money) 
{
	if (money < 0)
	{
		throw MinusException(money);
	}
	
	Balance += money;
}



		
int Account::WithDraw(int money)  
{
	if (money < 0)
	{
		throw MinusException(money);
	}
	
	if (Balance < money)
	{
		throw InsuffException(Balance, money);
	}

	Balance -= money;	
				
	return money;
}



void Account::ShowAllAccountInfo(void) const  
{
	cout<<"°èÁÂ ID: "<<AccID<<endl;
	cout<<"ÀÌ ¸§:  "<<ClientName<<endl;
	cout<<"ÀÜ ¾×: "<<Balance<<endl;
	cout<<endl;
}

