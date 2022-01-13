/*
 * AcoountHandler.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 *         ver: 0.10
 */


#include "AccountHandler.h"



AccountHandler::AccountHandler() : AccNum (0) 
{ }



		
void AccountHandler::ShowMenu(void) const
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
	
}



	
void AccountHandler::MakeAccount(void)
{
	int choice;
	
	cout<<"[������������]"<<endl;
	cout<<"1. ���뿹�ݰ��� ";
	cout<<"2. �ſ�ŷڰ��� "<<endl;
	cout<<"����: ";
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
		cout<<"�߸� �����߽��ϴ�."<<endl<<endl;
		return;
	}
	
}



				
void AccountHandler::MakeNormalAccount(void)
{
		
	int ID;
	int Balance;
	int InterestRate;
	String Name;
			
	cout<<"[���뿹�ݰ��� ����]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"�� ��: ";
	cin>>Name;
	cout<<"�Աݾ�: ";
	cin>>Balance; 
	cout<<"������: ";
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
			
	cout<<"�ſ�ŷڰ��� ����]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"�� ��: ";
	cin>>Name;
	cout<<"�Աݾ�: ";
	cin>>Balance; 
	cout<<"������: ";
	cin>>InterestRate;
	cout<<"�ſ���(1toA, 2toB, 3toC): "; 
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
	
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"�Աݾ�: ";
	cin>>Money;
	
	for(int i = 0; i < AccNum; i++)
	{
		if(AccountArr[i]->GetID() == ID)
		{
			AccountArr[i]->Deposit(Money);
			cout<<endl;
			cout<<"�ԱݿϷ�"<<endl;
			
			return;	
		}
	}
	cout<<" ��ȿ���� ���� ID �Դϴ�."<<endl<<endl;	
} 




void AccountHandler::WithDrawMoney(void)
{
	int Money;
	int ID;
	
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"��ݾ�: ";
	cin>>Money;
	
	for(int i = 0; i < AccNum; i++)
	{
		if(AccountArr[i]->GetID() == ID)
		{
			if(AccountArr[i]->WithDraw(Money) == 0)
			{
				cout<<endl;
				cout<<"�ܾ׺���"<<endl<<endl;
				return;
			}
			 
			cout<<endl;
			cout<<"��ݿϷ�"<<endl<<endl;
			
			return;
		}
    }		
	cout<<" ��ȿ���� ���� ID �Դϴ�."<<endl<<endl;	
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
