/*
 * Acoount.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.9
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
	Balance += money;
}



		
int Account::WithDraw(int money)  
{
	if( Balance < 0)
	{
		return 0;
	}
		
	else if (Balance - money < 0)
	{
		return 0;
	}

	Balance -= money;	
				
	return money;
}



void Account::ShowAllAccountInfo(void) const  
{
	cout<<"���� ID: "<<AccID<<endl;
	cout<<"�� ��:  "<<ClientName<<endl;
	cout<<"�� ��: "<<Balance<<endl;
	cout<<endl;
}

