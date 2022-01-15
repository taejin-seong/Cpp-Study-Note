/*
 * BankingSystemMain.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.12
 */


#include "AccountHandler.h"


int main(void)
{
	AccountHandler manger;
	int choice;
	
	while(1)
	{
		manger.ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case MAKE:
				manger.MakeAccount();
				break;
			
			case DEPOSIT:
				manger.DepositMoney();
				break;
			
			case WITHDRAW:
				manger.WithDrawMoney();
				break;
				
			case INQUIRE:
				manger.ShowAllAccountInfo();
				break;
				
			case EXIT:
				return 0;
			
			default:
				cout<<"유효하지 않는 메뉴번호 입니다."<<endl<<endl;	
		}	
	}
	
	return 0;
} 
