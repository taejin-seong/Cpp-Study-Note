/*
 * Acoount.c
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 *         ver: 0.7
 */


#include "Account.h"



Account::Account(int id, int moeny, char* name) :AccID(id), Balance(moeny) 
{
	ClientName = new char[strlen(name)+1];
	strcpy(ClientName, name);
}



		
Account::Account(const Account& copy)  :AccID(copy.AccID), Balance(copy.Balance) 
{
	ClientName = new char[strlen(copy.ClientName)+1];
	strcpy(ClientName, copy.ClientName);
	
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
	cout<<"°èÁÂID: "<<AccID<<endl;
	cout<<"ÀÌ ¸§: "<<ClientName<<endl;
	cout<<"ÀÜ ¾×: "<<Balance<<endl;
	cout<<endl;
}



		
Account::~Account()
{
	delete []ClientName;
}

