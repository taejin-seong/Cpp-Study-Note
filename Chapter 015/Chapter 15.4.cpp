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
		int reqDep; //��û �Ա޾�
				
	public:
	    DepositException(int money) : reqDep(money)
		{ }
		
		void ShowExceptionReason()
		{
			cout<<"[���� �޼���: "<<reqDep<<"�� �Ա޺Ұ�]"<<endl;
		} 
};



class WithdrawException
{
	private:
		int balance; //�ܰ� 
	
	public:
		WithdrawException(int money) : balance(money)
		{ }
		
		
		void ShowExceptionReason()
		{
			cout<<"[���� �޼���: �ܾ� "<<balance<<", �ܾ׺���]"<<endl;
		}
};




class Account
{
	private:
		char accNum[50]; //���� ��ȣ
		int balance; //�ܰ�
		
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
				
				//���ܰ�ü�� �ӽð�ü�� ���·� �����ϴ� ���� ����  
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
		 	cout<<"�ܰ�: "<<balance<<endl<<endl;
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
		virtual void ShowExceptionReason() = 0; //���� �����Լ� 
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
			cout<<"[���� �޼���: "<<reqDep<<"�� �Ա޺Ұ�]"<<endl;
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
			cout<<"[���� �޼���: �ܾ� "<<balance<<", �ܾ׺���]"<<endl;
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
		 	cout<<"�ܰ�: "<<balance<<endl<<endl;
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
		//�ּ�ó���� ���ؼ� �� ���徿 �����ؼ� ��� Ȯ�� 
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
	
	//BBB,CCC��ü�� ������ AAA ��ü������ (���), AAA��ü�� ������ BBB,CCC��ü�� �ƴϹǷ�
	//���ϴ� ����� ���� 
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
