#include <iostream>
#include <cstring>

//#define START1
//#define START2
#define START3
#define START4

using namespace std;






#ifdef START1

//ObjectPointer.cpp
class Person
{
	public:
		void Sleep()
		{
			cout<<"Sleep"<<endl;
		}
};


class Student : public Person
{
	public:
		void Study()
		{
			cout<<"Stduy"<<endl;
		}
};


class PartTimeStudent : public Student
{
	public:
		void Work()
		{
			cout<<"Work"<<endl;
		}
};


int main(void)
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();
	
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
}
#endif /* START1 */





#ifdef START2

//EmployeeManager2.cpp
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
		 	/*
		 	for (int i = 0; i < empNum; i++)
		 	{
		 		empList[i]->ShowSalaryInfo();
			 }
			 */
		 }
		 
		 
		 void ShowTotalSalary() const
		 {
		 	int sum = 0;
		 	/*
			for (int i = 0; i < empNum; i++)
		 	{
		 		sum += empList[i]->GetPay();
			}
			*/
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
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성 
	EmployeeHandler handler;
	
	//직원 등록 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));
	
	//이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	
	//이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	
	return 0;
	
}
#endif /* START2 */




#ifdef START3

//EmployeeManager3.cpp
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
		 	/*
		 	for (int i = 0; i < empNum; i++)
		 	{
		 		empList[i]->ShowSalaryInfo();
			 }
			 */
		 }
		 
		 
		 void ShowTotalSalary() const
		 {
		 	int sum = 0;
		 	/*
			for (int i = 0; i < empNum; i++)
		 	{
		 		sum += empList[i]->GetPay();
			}
			*/
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
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성 
	EmployeeHandler handler;
	
	//직원 등록 
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	
	//임시직 등록 
	TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);
	
	//영업직 등록
	SalesWorker* seller = new SalesWorker("HONG",1000,0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);
	
	//이번 달에 지불해야할 급여의 정보
	handler.ShowTotalSalary();
	return 0;
	
}
#endif /* START3 */
