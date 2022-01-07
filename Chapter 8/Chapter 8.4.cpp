#include <iostream>
#include <cstring> 

//OOP 단계별 프로젝트 6단계

// 은행계좌 관리 프로그램 ver 0.6


using namespace std;






//***********************************************************************************************
const int NAME_LEN = 20;

//사용자 메뉴 
enum{
	
	MAKE = 1, 
	DEPOSIT, 
	WITHDRAW,
	INQUIRE,
	EXIT
}; 

//신용등급 
enum{
	A = 7,
	B = 4,
	C = 2 
};

//생성할 계좌 선택 
enum{
	NORMAL = 1,
	CREDIT
	
};
//***********************************************************************************************





//***********************************************************************************************

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
		
		
		
		virtual void Deposit(int money) //예금 
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
//***********************************************************************************************





//***********************************************************************************************
class NormalAccount : public Account //보통예금계좌 
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
class HighCreditAccount : public NormalAccount //신용신뢰계좌 
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
		Account* AccountArr[100];  //Account 저장을 위한 배열 
		int AccNum ;               //저장된 Account 수 

	
	public:
		AccountHandler() : AccNum (0) {}
		
		
		
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
		
		
		
		
		void MakeCreditAccount(void)
		{
		
			int ID;
			int Balance;
			int InterestRate;
			int PlusRate;
			char Name[NAME_LEN];
			
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
		
		
		
		void DepositMoney(void)
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



		void WithDrawMoney(void)
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
			
			cout<<" 유효하지 않은 ID 입니다."<<endl<<endl;	
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
				cout<<"없는 항목입니다."<<endl<<endl;	
		}	
	}
	
	return 0;
} 
