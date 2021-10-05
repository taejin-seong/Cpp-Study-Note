#include <iostream> 
#include <cstring>

using namespace std;
//OOP �ܰ躰 ������Ʈ 1 �ܰ�

// ������� ���� ���α׷� 


const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void WithDraw(void);
void ShowAllAccountInfo(void);


enum{
	
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
}; // case���� �ʿ��� ������ ������ ���� 


typedef struct
{
	int AccID; // ���¹�ȣ 
	int Balance; // �� ��  
	char ClientName[NAME_LEN]; // ���̸� 

}AccountInfo;


AccountInfo AccountArr[100]; // AccountInfo ������ ���� �迭 
int AccNum = 0; // ����� AccountInfo �� 


int main(void)
{
	
	int Choice;
	
	while(1)
	{
		
		ShowMenu();
		cout<<"����: ";
		cin>>Choice;
		cout<<endl;
		
		switch(Choice)
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
		    	return 0;
		    
		    default:
		    	cout<<"���� �׸� �Դϴ�."<<endl<<endl;
			
		} 
		
	}	
	
	return 0;
	
	
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
	char Name[NAME_LEN];
	int Balance;
	
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";
	cin>>ID;
	cout<<"�� ��: ";
	cin>>Name;
	cout<<"�Աݾ�: ";
	cin>>Balance; 
	cout<<endl;

	
	AccountArr[AccNum].AccID = ID;
	AccountArr[AccNum].Balance = Balance;
	strcpy(AccountArr[AccNum].ClientName, Name);
	
	AccNum++;
	
	
}


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
		if(AccountArr[i].AccID == ID)
		{
			AccountArr[i].Balance += Money;
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
		if(AccountArr[i].AccID == ID)
		{
			if(AccountArr[i].Balance < Money)
			{
				cout<<"�ܾ׺���"<<endl<<endl;
			} 
			
			AccountArr[i].Balance  -= Money;
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
		cout<<"����ID: "<<AccountArr[i].AccID<<endl;
		cout<<"�� ��: "<<AccountArr[i].ClientName<<endl;
		cout<<"�� ��: "<<AccountArr[i].Balance<<endl;
		
	}
}











































