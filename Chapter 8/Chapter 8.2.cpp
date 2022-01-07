#include <iostream>
#include <cstring>


//#define START1
//#define START2
//#define START3
#define START4

using namespace std;




#ifdef START1

//FunctionOverride.cpp
class First
{
	public:
		void MyFunc()
		{
			cout<<"FirstFunc"<<endl;
		}
};



class Second : public First
{
	public:
		void MyFunc()
		{
			cout<<"SecondFunc"<<endl;
		}
};



class Third : public Second
{
	public:
		void MyFunc()
		{
			cout<<"ThirdFunc"<<endl;
		}
};

/* 
   22��, 33��, 44��: 
   MyFunc�Լ��� ���ؼ� �������̵� ���踦 �����ϰ� ����.
*/   

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;
	
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	
	delete tptr;
	
	return 0;
}
#endif /* START1 */





#ifdef 	START2
//!!* �����Լ�  

//FunctionVirtualOverride.cpp
class First
{
	public:
		virtual void MyFunc()
		{
			cout<<"FirstFunc"<<endl;
		}
};


class Second : public First
{
	public:
		virtual void MyFunc()
		{
			cout<<"SecondFunc"<<endl;
		}
};


class Third : public Second
{
	public:
		virtual void MyFunc()
		{
			cout<<"ThirdFunc"<<endl;
		}
};


int main(void)
{
	Third*  tptr = new Third();
	Second* sptr = tptr;
	First*  fptr = sptr;
	
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	
	delete tptr;
	
	return 0;
}
#endif /* START2 */





#ifdef START3

//EmployeeManager4.cpp
class Employee  //�߻� Ŭ���� ~ ��ü ������ �Ұ����� Ŭ���� 
{
	private:
		char name[100];
	
	public:
		Employee(char* name)
		{
			strcpy(this->name, name);
		}
		
		void ShowYourName() const
		{
			cout<<"name: "<<name<<endl;
		}
		
		virtual int GetPay() const = 0;  //���� �����Լ� 
		
		virtual void ShowSalaryInfo() const = 0;  //���� �����Լ� 

};




class PermanentWorker : public Employee 
{
	private:
		int salary;
		
	public:
		PermanentWorker(char* name, int money) : Employee(name), salary(money) { } 
		
		
		int GetPay() const
		{
			return salary;
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl;
		}
};



class TemporaryWorker : public Employee
{
	private:
		int workTime;
		int payPerHour;
		
	public:
		TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }
		
		
		void AddWorkTime(int time)
		{
			workTime+=time;
		}
		
		
		int GetPay() const
		{
			return workTime * payPerHour;
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl;
		} 
	
};



class SalesWorker : public PermanentWorker
{
	private:
		int salesResult;
		double bonusRatio;
		
	public:
		SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }
		
		
		void AddSalesResult(int vlaue)
		{
			salesResult += vlaue;
		}
		
		
		int GetPay() const
		{
			return PermanentWorker::GetPay() + (int)(salesResult* bonusRatio);
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl; 
		}
};



class EmployeeHandler 
{
	private:
		Employee* empList[50];
		int empNum;
		
	public:
		 EmployeeHandler() : empNum(0) {}
		 
		 
		 void AddEmployee(Employee* emp)
		 {
		 	empList[empNum ++] = emp;
		 }
		 
		 
		 void ShowAllSalaryInfo() const
		 {
		 	
		 	for (int i = 0; i < empNum; i++)
		 	{
		 		empList[i]->ShowSalaryInfo();
			}
			 
		 }
		 
		 
		 void ShowTotalSalary() const
		 {
		 	int sum = 0;
		 	
			for (int i = 0; i < empNum; i++)
		 	{
		 		sum += empList[i]->GetPay();
			}
			
			cout<<"salary sum:  "<<sum<<endl;
		 }
		 
		 
		 ~EmployeeHandler()
		 {
		 	for(int i = 0; i < empNum; i++)
		 	{
		 		delete empList[i];
			}
		 }		 
		 
};


int main(void)
{
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü���� 
	EmployeeHandler handler;
	
	//���� ��� 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	
	//�ӽ��� ��� 
	TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);
	
	//������ ���
	SalesWorker* seller = new SalesWorker("HONG",1000,0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);
	
	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	
	//�̹� �޿� �����ؾ� �� �޿��� ���� 
	handler.ShowTotalSalary();
	
	return 0;
	
}
#endif /* START3 */





/****************************
 
  EmployeeManager4.cpp�� Ȯ�� 
 
****************************/

#ifdef START4

//p354 Question 8-1 NO.1
class Employee   
{
	private:
		char name[100];
	
	public:
		Employee(char* name)
		{
			strcpy(this->name, name);
		}
		
		void ShowYourName() const
		{
			cout<<"name: "<<name<<endl;
		}
		
		virtual int GetPay() const = 0;   
		
		virtual void ShowSalaryInfo() const = 0;   

};




class PermanentWorker : public Employee 
{
	private:
		int salary;
		
	public:
		PermanentWorker(char* name, int money) : Employee(name), salary(money) { } 
		
		
		int GetPay() const
		{
			return salary;
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl;
		}
};



class TemporaryWorker : public Employee
{
	private:
		int workTime;
		int payPerHour;
		
	public:
		TemporaryWorker(char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }
		
		
		void AddWorkTime(int time)
		{
			workTime+=time;
		}
		
		
		int GetPay() const
		{
			return workTime * payPerHour;
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl;
		} 
	
};



class SalesWorker : public PermanentWorker
{
	private:
		int salesResult;
		double bonusRatio;
		
	public:
		SalesWorker(char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }
		
		
		void AddSalesResult(int vlaue)
		{
			salesResult += vlaue;
		}
		
		
		int GetPay() const
		{
			return PermanentWorker::GetPay() + (int)(salesResult* bonusRatio);
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<GetPay()<<endl<<endl; 
		}
};


namespace RISK_LEVEL
{
	enum
	{
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
		 
	};
}

class ForeignSalesWorker : public SalesWorker
{
	private:
		const int RiskLevel;
	
	public:
		
		ForeignSalesWorker(char* name, int money, double ratio, int risklevel) 
		                  : SalesWorker(name, money, ratio), RiskLevel(risklevel) { }
		                  
		int GetRiskPay() const
		{
			return (int)(SalesWorker::GetPay() *(RiskLevel/100.0));
		}
		
				
		int GetPay() const
		{
			return SalesWorker::GetPay() + GetRiskPay();
		}
		
		
		void ShowSalaryInfo() const
		{
			ShowYourName();
			cout<<"salary: "<<SalesWorker::GetPay()<<endl; 
			cout<<"risk pay: "<<GetRiskPay()<<endl; 
			cout<<"sum: "<<GetPay()<<endl<<endl;
		}                  
};


class EmployeeHandler 
{
	private:
		Employee* empList[50];
		int empNum;
		
	public:
		 EmployeeHandler() : empNum(0) {}
		 
		 
		 void AddEmployee(Employee* emp)
		 {
		 	empList[empNum ++] = emp;
		 }
		 
		 
		 void ShowAllSalaryInfo() const
		 {
		 	
		 	for (int i = 0; i < empNum; i++)
		 	{
		 		empList[i]->ShowSalaryInfo();
			}
			 
		 }
		 
		 
		 void ShowTotalSalary() const
		 {
		 	int sum = 0;
		 	
			for (int i = 0; i < empNum; i++)
		 	{
		 		sum += empList[i]->GetPay();
			}
			
			cout<<"salary sum:  "<<sum<<endl;
		 }
		 
		 
		 ~EmployeeHandler()
		 {
		 	for(int i = 0; i < empNum; i++)
		 	{
		 		delete empList[i];
			}
		 }		 
		 
};


int main(void)
{
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü���� 
	EmployeeHandler handler;
	
	//�ؿ� ������ ��� 
	ForeignSalesWorker* fsller1 = new ForeignSalesWorker("Hong", 1000, 0.1 , RISK_LEVEL::RISK_A);
	fsller1->AddSalesResult(7000);
	handler.AddEmployee(fsller1);
	
	ForeignSalesWorker* fsller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_A);
	fsller2->AddSalesResult(7000);
	handler.AddEmployee(fsller2);
	
	ForeignSalesWorker* fsller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fsller2->AddSalesResult(7000);
	handler.AddEmployee(fsller3);
	
	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();
	
	return 0; 
	
	
	return 0;
	
}

#endif /* START4 */
