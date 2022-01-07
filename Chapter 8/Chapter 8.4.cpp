#include <iostream>
#include <cstring> 

//OOP �ܰ躰 ������Ʈ 6�ܰ�

// ������� ���� ���α׷� ver 0.6


using namespace std;






//***********************************************************************************************
const int NAME_LEN = 20;

//����� �޴� 
enum{
	
	MAKE = 1, 
	DEPOSIT, 
	WITHDRAW,
	INQUIRE,
	EXIT
}; 

//�ſ��� 
enum{
	A = 7,
	B = 4,
	C = 2 
};

//������ ���� ���� 
enum{
	NORMAL = 1,
	CREDIT
	
};
//***********************************************************************************************





//***********************************************************************************************

class Account
{
	private:
		int AccID;        //���¹�ȣ 
		int Balance;      //�ܾ�
		char* ClientName; //���̸� 
	
	public:
		Account(int id, int moeny, char* name) :AccID(id), Balance(moeny) //���� �輳 
		{
			ClientName = new char[strlen(name)+1];
			strcpy(ClientName, name);
		}
		
		
		
		Account(const Account& copy)  :AccID(copy.AccID), Balance(copy.Balance)  // ���� ���� 
		{
			ClientName = new char[strlen(copy.ClientName)+1];
			strcpy(ClientName, copy.ClientName);
	
		}
		
		
		
		int GetID(void) const //ID ��ȯ 
		{
			return AccID;
		}
		
		
		
		virtual void Deposit(int money) //���� 
		{
			Balance += money;
		}
		
		
		
		int WithDraw(int money) //��� 
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
		
		
	
		void ShowAllAccountInfo(void) const //���� ��ȸ 
		{
			cout<<"����ID: "<<AccID<<endl;
			cout<<"�� ��: "<<ClientName<<endl;
			cout<<"�� ��: "<<Balance<<endl;
			cout<<endl;
		}
		
		
		
		~Account()
		{
			delete []ClientName;
		}
};
//***********************************************************************************************





//***********************************************************************************************
class NormalAccount : public Account //���뿹�ݰ��� 
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

//***********************************************************************************************





//***********************************************************************************************
class HighCreditAccount : public NormalAccount //�ſ�ŷڰ��� 
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
//*********************************************************************************************** 





//*********************************************************************************************** 
   
class AccountHandler
{
	private:
		Account* AccountArr[100];  //Account ������ ���� �迭 
		int AccNum ;               //����� Account �� 

	
	public:
		AccountHandler() : AccNum (0) {}
		
		
		
		void ShowMenu(void) const
		{
			cout<<"-----Menu-----"<<endl;
			cout<<"1. ���°���"<<endl;
			cout<<"2. �� ��"<<endl;
			cout<<"3. �� ��"<<endl;
			cout<<"4. �������� ��ü ���"<<endl;
			cout<<"5. ���α׷� ����"<<endl;
	
		}
		
		
		
		void MakeAccount(void)
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
			
			else
			{
				MakeCreditAccount();
			}
	
		}
		
		
		
				
		void MakeNormalAccount(void)
		{
		
			int ID;
			int Balance;
			int InterestRate;
			char Name[NAME_LEN];
			
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
		
		
		
		
		void MakeCreditAccount(void)
		{
		
			int ID;
			int Balance;
			int InterestRate;
			int PlusRate;
			char Name[NAME_LEN];
			
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
		
		
		
		void DepositMoney(void)
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



		void WithDrawMoney(void)
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
		
		
		
		void ShowAllAccountInfo(void) const
		{
			for(int i = 0; i < AccNum; i++)
			{
				AccountArr[i]->ShowAllAccountInfo();
				cout<<endl;
			}
		}	
		
		
		
		~AccountHandler()
		{
			for (int i =0; i < AccNum; i++)
			{
				delete AccountArr[i];
			}
		}

};
//*********************************************************************************************** 




		
//***********************************************************************************************  		
int main(void)
{
	AccountHandler manger;
	int choice;
	
	while(1)
	{
		manger.ShowMenu();
		cout<<"����: ";
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
				cout<<"���� �׸��Դϴ�."<<endl<<endl;	
		}	
	}
	
	return 0;
} 
