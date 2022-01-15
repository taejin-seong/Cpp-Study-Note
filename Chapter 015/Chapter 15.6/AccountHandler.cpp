/*
 * AcoountHandler.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.12
 */


#include "AccountHandler.h"


AccountHandler::AccountHandler() : AccNum (0) 
{ }



	
void AccountHandler::ShowMenu(void) const
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	
}





void AccountHandler::MakeAccount(void)
{
	int choice;
	
	cout<<"[계좌종류선택]"<<endl;
	cout<<"1. 보통예금계좌 ";
	cout<<"2. 신용신뢰계좌 "<<endl;
	cout<<"선택: ";
	cin>>choice;
			
	if(choice == NORMAL)
	{
		MakeNormalAccount();	
	}
			
	else if (choice == CREDIT) 
	{
		MakeCreditAccount();
	}
	
	else
	{
		cout<<"유효하지 않는 번호입니다."<<endl<<endl;
		return;
	}
	
}



				
void AccountHandler::MakeNormalAccount(void)
{
		
	int ID;
	int Balance;
	int InterestRate;
	String Name;
			
	cout<<"[보통예금계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	cout<<"이 름: ";
	cin>>Name;
	cout<<"입금액: ";
	cin>>Balance; 
	cout<<"이자율: ";
	cin>>InterestRate;
	cout<<endl;

				
	AccountArr[AccNum++] = new NormalAccount(ID, Balance, Name, InterestRate);
}	



		
void AccountHandler::MakeCreditAccount(void)
{
		
	int ID;
	int Balance;
	int InterestRate;
	int PlusRate;
	String Name;
			
	cout<<"신용신뢰계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	cout<<"이 름: ";
	cin>>Name;
	cout<<"입금액: ";
	cin>>Balance; 
	cout<<"이자율: ";
	cin>>InterestRate;
	cout<<"신용등급(1toA, 2toB, 3toC): "; 
	cin>>PlusRate;
	cout<<endl;

	switch(PlusRate)
	{
		case 1:
			AccountArr[AccNum++] = new HighCreditAccount(ID, Balance, Name, InterestRate, A);
			break;
					
		case 2:
			AccountArr[AccNum++] = new HighCreditAccount(ID, Balance, Name, InterestRate, B);
			break;
				
		case 3:
			AccountArr[AccNum++] = new HighCreditAccount(ID, Balance, Name, InterestRate, C);
			break;
	}		
		
}	



		
void AccountHandler::DepositMoney(void)
{
	int Money;
	int ID;
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	
	while (true)
	{
		cout<<"입금액: ";
		cin>>Money;
		
		try
		{
			for(int i = 0; i < AccNum; i++)
			{
				if(AccountArr[i]->GetID() == ID)
				{
					AccountArr[i]->Deposit(Money);
					cout<<endl;
					cout<<"입금완료"<<endl;
			
					return;	
				}
			}
			cout<<" 유효하지 않은 ID 입니다."<<endl<<endl;	
			
			return;
		}
		
		catch(MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout<<"입금액만 재입력하세요."<<endl;
		}
	}	
} 




void AccountHandler::WithDrawMoney(void)
{
	int Money;
	int ID;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	
	while (true)
	{
		cout<<"출금액: ";
		cin>>Money;
		
		try
		{
			for(int i = 0; i < AccNum; i++)
			{
				if(AccountArr[i]->GetID() == ID)
				{
					AccountArr[i]->WithDraw(Money);
					cout<<"출금완료"<<endl<<endl;
			
					return;
				}
    		}		
			cout<<" 유효하지 않은 ID 입니다."<<endl<<endl;
			
			return;	
		}
	
		catch(MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout<<"출금액만 재입력하세요."<<endl;
		}
		
		catch(InsuffException& expt)
		{
			expt.ShowExceptionInfo();
			cout<<"출금액만 재입력하세요."<<endl;
		}
	}
}



		
void AccountHandler::ShowAllAccountInfo(void) const
{
	for(int i = 0; i < AccNum; i++)
	{
		AccountArr[i]->ShowAllAccountInfo();
		cout<<endl;
	}
}	



		
AccountHandler::~AccountHandler()
{
	for (int i =0; i < AccNum; i++)
	{
		delete AccountArr[i];
	}
}
