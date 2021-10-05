#include <iostream> 
#include <cstring>

using namespace std;
//OOP 단계별 프로젝트 1 단계

// 은행계좌 관리 프로그램 


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
}; // case문에 필요한 열거형 연산자 선언 


typedef struct
{
	int AccID; // 계좌번호 
	int Balance; // 잔 액  
	char ClientName[NAME_LEN]; // 고객이름 

}AccountInfo;


AccountInfo AccountArr[100]; // AccountInfo 저장을 위한 배열 
int AccNum = 0; // 저장된 AccountInfo 수 


int main(void)
{
	
	int Choice;
	
	while(1)
	{
		
		ShowMenu();
		cout<<"선택: ";
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
		    	cout<<"없는 항목 입니다."<<endl<<endl;
			
		} 
		
	}	
	
	return 0;
	
	
}

void ShowMenu(void)
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	
}



void MakeAccount(void)
{
	int ID;
	char Name[NAME_LEN];
	int Balance;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	cout<<"이 름: ";
	cin>>Name;
	cout<<"입금액: ";
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
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	cout<<"입금액: ";
	cin>>Money;
	
	for(int i = 0; i < AccNum; i++)
	{
		if(AccountArr[i].AccID == ID)
		{
			AccountArr[i].Balance += Money;
			cout<<"입금완료"<<endl;
			
			return;	
		}
		
	}

	cout<<" 유효하지 않은 ID 입니다."<<endl<<endl;
}



void WithDraw(void)
{
	int Money;
	int ID;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>ID;
	cout<<"출금액: ";
	cin>>Money;
	
	for(int i = 0; i < AccNum; i++)
	{
		if(AccountArr[i].AccID == ID)
		{
			if(AccountArr[i].Balance < Money)
			{
				cout<<"잔액부족"<<endl<<endl;
			} 
			
			AccountArr[i].Balance  -= Money;
			cout<<"출금완료"<<endl<<endl;
			return;
			
		}
		
	}
	
	cout<<" 유효하지 않은 ID 입니다."<<endl<<endl;
	
}



void ShowAllAccountInfo(void)
{
	
	for(int i = 0; i < AccNum; i++)
	{
		cout<<"계좌ID: "<<AccountArr[i].AccID<<endl;
		cout<<"이 름: "<<AccountArr[i].ClientName<<endl;
		cout<<"잔 액: "<<AccountArr[i].Balance<<endl;
		
	}
}











































