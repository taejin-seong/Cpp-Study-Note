#include <iostream>
#include <cstring> 

//OOP 단계별 프로젝트 5단계

// 은행계좌 관리 프로그램 ver 0.5


using namespace std;


const int NAME_LEN = 20;

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
		int AccID;        //계좌번호 
		int Balance;      //잔액
		char* ClientName; //고객이름 
	
	public:
		Account(int id, int moeny, char* name) :AccID(id), Balance(moeny) //계좌 계설 
		{
			ClientName = new char[strlen(name)+1];
			strcpy(ClientName, name);
		}
		
		Account(const Account& copy)  :AccID(copy.AccID), Balance(copy.Balance)  // 깊은 복사 
		{
			ClientName = new char[strlen(copy.ClientName)+1];
			strcpy(ClientName, copy.ClientName);
	
		}
		
		int GetID(void) const //ID 반환 
		{
			return AccID;
		}
		
		void Deposit(int money) //예금 
		{
			Balance += money;
		}
		
		int WithDraw(int money) //출금 
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
		
		void ShowAllAccountInfo(void) const //계좌 조회 
		{
			cout<<"계좌ID: "<<AccID<<endl;
			cout<<"이 름: "<<ClientName<<endl;
			cout<<"잔 액: "<<Balance<<endl;
			cout<<endl;
		}
		
		~Account()
		{
			delete []ClientName;
		}
};

 
class AccountHandler
{
	private:
		Account* AccountArr[100];  //Account 저장을 위한 배열 
		int AccNum = 0;            //저장된 Account 수 

	
	public:
		void ShowMenu(void) const
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
			int Balance;
			char Name[NAME_LEN];
	
			cout<<"[계좌개설]"<<endl;
			cout<<"계좌ID: ";
			cin>>ID;
			cout<<"이 름: ";
			cin>>Name;
			cout<<"입금액: ";
			cin>>Balance; 
			cout<<endl;

			AccountArr[AccNum++] = new Account(ID, Balance, Name);
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
				if(AccountArr[i]->GetID() == ID)
				{
					AccountArr[i]->Deposit(Money);
					cout<<endl;
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
				if(AccountArr[i]->GetID() == ID)
				{
					if(AccountArr[i]->WithDraw(Money) == 0)
					{
						cout<<endl;
						cout<<"잔액부족"<<endl<<endl;
						return;
					}
			 
					cout<<endl;
					cout<<"출금완료"<<endl<<endl;
					return;
				}
			}
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
				manger.Deposit();
				break;
			
			case WITHDRAW:
				manger.WithDraw();
				break;
				
			case INQUIRE:
				manger.ShowAllAccountInfo();
				break;
				
			case EXIT:
				return 0;
			
			default:
				cout<<"없는 항목입니다."<<endl<<endl;	
		}	
	}
	
	return 0;
} 




