#include <iostream>

//#define START1
//#define START2
//#define START3
//#define START4
//#define START5
#define START6

using namespace std;


#ifdef START1

//FirstOperationOverloading.cpp
class First
{
	private:
		int num1, num2;
		
	public:
		First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
		{ }
		
		void ShowData()
		{
			cout<<num1<<", "<<num2<<endl;
		}
};



class Second
{
	private:
		int num3, num4;
	
	public:
		Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
		{ }
		
		void ShowData()
		{
			cout<<num3<<", "<<num4<<endl;
		}
		
		Second& operator=(const Second& ref)
		{
			cout<<"Second& operator=()"<<endl;
			num3 = ref.num3;
			num4 = ref.num4;
			
			return *this;
		}
};



int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;	
	fcpy = fsrc;
	scpy = ssrc;
	fcpy.ShowData();
	scpy.ShowData();
	
	
	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;
	
	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	
	return 0;
	

}
#endif /* START1 */






#ifdef START2

#include <cstring>

//AssingShallowCopyError.cpp
class Person
{
	private:
		char* name;
		int age;
	
	public:
		Person(char* myname, int myage)
		{
			int len = strlen(myname)+1;
			name = new char[len];
			strcpy(name, myname);
			
			age = myage;
		}
		/*
		Person& operator=(const Person& ref)  // 대입연산자는 생성자가 아님. 
		{ 
			delete []name; 
		
			int len = strlen(ref.name)+1;
			name = new char[len];
			strcpy(name, ref.name);
			
			age = ref.age;
			return *this;
		}
		*/
		
		void ShowPersonInfo() const
		{
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl;
		}
		
		~Person()
		{
			delete []name;
			cout<<"called destructor!"<<endl;
		}
};



int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 21);
	
	man2 = man1; //대입 연산자 
	
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	return 0;
}
#endif /* START2 */






#ifdef START3

//inheritAassignOperation.cpp
class First
{
	private:
		int num1, num2;
		
	public:
		First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
		{ }
		
		void ShowData()
		{
			cout<<num1<<", "<<num2<<endl;
		}
		
		First& operator=(const First& ref)
		{
			cout<<"First& operator=()"<<endl;
			num1=ref.num1;
			num2=ref.num2;
			
			return *this;
		} 
};




class Second : public First
{
	private:
		int num3, num4;
	
	public:
		Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4)
		{ }
		
		void ShowData()
		{
			First::ShowData();
			cout<<num3<<", "<<num4<<endl;
		}
		/*
		Second& operator=(const Second& ref)
		{
			
			cout<<"Second& operator=()"<<endl;
			num3 = ref.num3;
			num4 = ref.num4;
			
			return *this;
		}
		*/
		
		/*
		Second& operator=(const Second& ref)
		{
			
			cout<<"Second& operator=()"<<endl;
			First::operator=(ref);
			num3 = ref.num3;
			num4 = ref.num4;
			
			return *this;
		}
		*/
		
};




int main(void)
{
	Second ssrc(111, 222, 333 ,444);
	Second scpy(0, 0, 0, 0);
	
	scpy = ssrc;
	scpy.ShowData();
	
	return 0;
};


#endif /* START3 */






#ifdef START4

//p452 Question 11-1 NO.1
class Gun
{
	private:
		int bullet;
	
	public:
		Gun(int bnum) : bullet(bnum)
		{
		
		}
		
		void Shot()
		{
			cout<<"BBANG!"<<endl;
			bullet --;
		}
};





class Police
{
	private:
		int handcuffs;
		Gun* pistol;
		
	public:
		Police(int bnum, int bcuff) : handcuffs(bcuff)
		{
			if(bnum > 0)
			{
				pistol = new Gun(bnum);
			}
			
			else
			{
				pistol = NULL;
			}
			
		}
		
		Police(const Police& ref) : handcuffs(ref.handcuffs)
		{
			if(ref.pistol !=  NULL)
			{
				pistol = new Gun(*(ref.pistol));
			}
			
			else
			{
				pistol = NULL;
			}
		}
		
		
		Police& operator=(const Police& ref)
		{
			if(pistol != NULL)
			{
				delete pistol;
			}
			
			if(ref.pistol != NULL)
			{
				pistol = new Gun(*(ref.pistol));
				
			}
			
			else
			{
				pistol = NULL;
			}
			
			handcuffs = ref.handcuffs;
			
			return *this;

		}
		
		
		void PutHandcuff()
		{
			cout<<"SNAP!"<<endl;
			handcuffs--; 
		}
		
		void Shot()
		{
			if (pistol == NULL)
			{
				cout<<"Hut BBANG"<<endl;
			}
			
			else
			{
				pistol->Shot();
			}
		}	
};





int main(void)
{
	Police pman1(5,3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0,3);
	pman2.Shot();
	pman2.PutHandcuff();
	
	return 0;

}
#endif /* START4 */







#ifdef START5

#include <cstring>

//p453 Question 11-1 NO.2
class Book
{
	private:
		char *title; //책의 제목 
		char  *isbn;  //국제표준도서번호 
		 int  price; //책의 정가 
	
	public:
		Book (char* title, char* isbn, int pri) :price(pri)
		{
			this->title = new char[strlen(title)+1];
			this->isbn = new char[strlen(isbn)+1];
			
			strcpy(this->title, title);
			strcpy(this->isbn, isbn);
			
		}
		
		
		Book (const Book& ref) :price(ref.price)
		{
			this->title = new char[strlen(ref.title)+1];
			this->isbn = new char[strlen(ref.isbn)+1];
			
			strcpy(this->title, ref.title);
			strcpy(this->isbn, ref.isbn);		
		}
		
		
		Book& operator= (const Book& ref)
		{
			delete []title;
			delete []isbn;
			
			title = new char[strlen(ref.title)+1];
			isbn  = new char[strlen(ref.isbn)+1];
			
			strcpy(title, ref.title);
			strcpy(isbn, ref.isbn);
			
			return *this;
		}
		
		void ShowBookInfo()
		{
			cout<<"제목: "<<title<<endl;
			cout<<"ISBN: "<<isbn<<endl;
			cout<<"가격: "<<price<<endl; 
		}
		
		~Book()
		{
			delete []title;
			delete []isbn;
		}
		
};





class EBook :public Book
{
	private:
		char* DRMKey; //보안관련 키 
		
	public:
		EBook(char* title, char* isbn, int pri, char* DRMKey) :Book(title, isbn, pri)
		{
			this->DRMKey = new char[strlen(DRMKey)+1];
			
			strcpy(this->DRMKey, DRMKey);
		}
		
		EBook(const EBook& ref) : Book(ref)
		{
			DRMKey = new char[strlen(ref.DRMKey)+1];
			strcpy(DRMKey, ref.DRMKey);
		}
		
		
		EBook& operator=(const EBook& ref)
		{
			Book::operator=(ref);
			
			delete []DRMKey;
		
			DRMKey = new char[strlen(ref.DRMKey)+1];
			strcpy(DRMKey, ref.DRMKey);
			
			return *this;
		}
		
		
		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout<<"인증키: "<<DRMKey<<endl; 
		}
		
		~EBook()
		{
			delete []DRMKey;
		}
};





int main(void)
{
	EBook ebook1("좋은 C++", "555-1234-890-0", 20000, "dx0wk9u1n1");
	EBook ebook2 = ebook1;
	
	ebook1.ShowEBookInfo();
	cout<<endl;
	
	EBook ebook3("좋은 C++", "555-1234-890-1", 10000, "fdx9w0i8kiw");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	cout<<endl;
	
	return 0;
	
}
#endif /* START5 */







#ifdef START6

//Improvelinit.cpp
class AAA
{
	private:
		int num;
	
	public:
		AAA(int n = 0) : num(n)
		{
			cout<<"AAA(int n =0)"<<endl;
		}
		
		AAA(const AAA& ref) : num(ref.num)
		{
			cout<<"AAA(cout AAA& ref)"<<endl;
		}
		
		AAA& operator=(const AAA& ref)
		{
			num = ref.num;
			cout<<"operator=(const AAA& ref)"<<endl;
		}
};



class BBB
{
	private:
		AAA men;
	
	public:
		BBB(const AAA& ref) : men(ref)
		{ }
};



class CCC
{
	private:
		AAA men;
		
	public:
		CCC(const AAA& ref)
		{
			men = ref;
		}
};



int main(void)
{
	AAA obj1(12);
	cout<<"********************"<<endl;
	
	BBB obj2(obj1);
	cout<<"********************"<<endl;
	
	CCC obj3(obj1);
	
	return 0;
}
#endif /* START6 */
