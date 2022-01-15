#include <iostream>
#include <cstring>


//#define START1
//#define START2 
#define START3


using namespace std;


#ifdef START1

//ATMSim.cpp
class DepositException
{
	private:
		int reqDep; //요청 입급액
				
	public:
	    DepositException(int money) : reqDep(money)
		{ }
		
		void ShowExceptionReason()
		{
			cout<<"[예외 메세지: "<<reqDep<<"는 입급불가]"<<endl;
		} 
};



class WithdrawException
{
	private:
		int balance; //잔고 
	
	public:
		WithdrawException(int money) : balance(money)
		{ }
		
		
		void ShowExceptionReason()
		{
			cout<<"[예외 메세지: 잔액 "<<balance<<", 잔액부족]"<<endl;
		}
};




class Account
{
	private:
		char accNum[50]; //계좌 번호
		int balance; //잔고
		
	public:
	    Account(char* acc, int money) : balance(money)
		{
			strcpy(accNum, acc);
		} 
		
		
		
		
		void Deposit(int money) throw (DepositException)
		{
			if(money < 0)
			{
				DepositException expn(money);
				
				throw expn;
				
				//예외객체는 임시객체의 형태로 생성하는 것이 보통  
				//throw DepositException(money); 
			}
			
			balance += money;
		} 
		
		
		
		
		void Withdraw(int money) throw (WithdrawException)
		{
			if(money > balance)
			{
				throw WithdrawException(balance);
			}
			
			balance -= money;
		 } 
		 
		 
		 
		 
		 void ShowMyMoney()
		 {
		 	cout<<"잔고: "<<balance<<endl<<endl;
		 }
};





int main(void)
{
	Account myAcc("56789-827120", 5000);
	
	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	
	
	catch(DepositException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	
	
	
	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	
	
	
	catch(WithdrawException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	
	
	return 0;

}
#endif /* START1*/







#ifdef START2

//ATMSim2.cpp
class AccountException
{
	public:
		virtual void ShowExceptionReason() = 0; //순수 가상함수 
};




class DepositException : public AccountException
{
	private:
		int reqDep;
				
	public:
	    DepositException(int money) : reqDep(money)
		{ }
		
		void ShowExceptionReason()
		{
			cout<<"[예외 메세지: "<<reqDep<<"는 입급불가]"<<endl;
		} 
};



class WithdrawException : public AccountException
{
	private:
		int balance; 
	
	public:
		WithdrawException(int money) : balance(money)
		{ }
		
		
		void ShowExceptionReason()
		{
			cout<<"[예외 메세지: 잔액 "<<balance<<", 잔액부족]"<<endl;
		}
};







class Account
{
	private:
		char accNum[50]; 
		int balance; 
		
	public:
	    Account(char* acc, int money) : balance(money)
		{
			strcpy(accNum, acc);
		} 
		
		
		
		
		void Deposit(int money) throw (AccountException)
		{
			if(money < 0)
			{
				throw DepositException(money); 
			}
			
			balance += money;
		} 
		
		
		
		
		void Withdraw(int money) throw (AccountException)
		{
			if(money > balance)
			{
				throw WithdrawException(balance);
			}
			
			balance -= money;
		 } 
		 
		 
		 
		 
		 void ShowMyMoney()
		 {
		 	cout<<"잔고: "<<balance<<endl<<endl;
		 }
};





int main(void)
{
	Account myAcc("56789-827120", 5000);
	
	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	
	
	catch(AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	
	
	
	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	
	
	
	catch(AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	
	
	return 0;

}

#endif /* START2 */





#ifdef START3

//CatchFlow.cpp
class AAA
{
	public:
		void ShowYou()
		{
			cout<<"AAA exception!"<<endl;
		}
};


class BBB : public AAA
{
	public:
	    void ShowYou()
	    {
	     	cout<<"BBB exception!"<<endl;
     	}
};



class CCC : public BBB
{
	public:
		void ShowYou()
		{
			cout<<"CCC exception!"<<endl;
		}
};



void ExceptionGenrator(int expn)
{
	if (expn == 1)
	{
		throw AAA();
	}
	
	else if (expn == 2)
	{
		throw BBB();
	}
	
	else
	{
		throw CCC();
	}
}




int main(void)
{
	try
	{
		//주석처리를 통해서 한 문장씩 실행해서 결과 확인 
//		ExceptionGenrator(3);
		ExceptionGenrator(2);
//		ExceptionGenrator(1);
	}
	
	catch(AAA& expn)
	{
		cout<<"catch(AAA& expn)"<<endl;
		expn.ShowYou();
	}
	
	catch(BBB& expn)
	{
		cout<<"catch(BBB& expn)"<<endl;
		expn.ShowYou();
	}
	
	catch(CCC& expn)
	{
		cout<<"catch(CCC& expn)"<<endl;
		expn.ShowYou();
	}
	
	//BBB,CCC객체는 일종의 AAA 객체이지만 (상속), AAA객체는 일종의 BBB,CCC객체가 아니므로
	//원하는 결과를 도출 
/*	
	catch(CCC& expn)
	{
		cout<<"catch(CCC& expn)"<<endl;
		expn.ShowYou();
	}
	
	catch(BBB& expn)
	{
		cout<<"catch(BBB& expn)"<<endl;
		expn.ShowYou();
	}
	
		catch(AAA& expn)
	{
		cout<<"catch(AAA& expn)"<<endl;
		expn.ShowYou();
	}
*/	
	
	return 0;
}
#endif /* START3 */
