#include <iostream>
#include <cstring> 

//OOP �ܰ躰 ������Ʈ 3�ܰ�

// ������� ���� ���α׷� ver 0.3


using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);            //�޴���� 
void MakeAccount(void);         //���°��� 
void Deposit(void);             //�Ա� 
void WithDraw(void);            //��� 
void ShowAllAccountInfo(void);  //�ܾ���ȸ 


enum{
	
	MAKE = 1, 
	DEPOSIT, 
	WITHDRAW,
	INQUIRE,
	EXIT
}; 


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
		
		int GetID(void) //ID ��ȯ 
		{
			return AccID;
		}
		
		void Deposit(int money) //���� 
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
		
		void ShowAllAccountInfo(void) //���� ��ȸ 
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



Account* AccountArr[100];  //Account ������ ���� �迭 
int AccNum = 0;            //����� Account �� 
 


int main(void)
{
	int choice;
	
	while(1)
	{
		ShowMenu();
		cout<<"����: ";
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case MAKE:
				MakeAccount();
				break;
			
			case DEPOSIT:
				Deposit();
				break;
			
			case WITHDRAW:
				WithDraw();
				break;
				
			case INQUIRE:
				ShowAllAccountInfo();
				break;
				
			case EXIT:
				for (int i =0; i < AccNum; i++)
				{
					delete AccountArr[i];
				}
				
				return 0;
			
			default:
				cout<<"���� �׸��Դϴ�."<<endl<<endl;	
	
		}	
	} 
}




void ShowMenu(void)
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
	int ID;
	int Balance;
	char Name[NAME_LEN];
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"�� ��: ";
	cin>>Name;
	cout<<"�Աݾ�: ";
	cin>>Balance; 
	cout<<endl;

	
	AccountArr[AccNum++] = new Account(ID, Balance, Name);
		
};



void Deposit(void)
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



void WithDraw(void)
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



void ShowAllAccountInfo(void)
{
	for(int i = 0; i < AccNum; i++)
	{
		AccountArr[i]->ShowAllAccountInfo();
		cout<<endl;	
	}
	
}
