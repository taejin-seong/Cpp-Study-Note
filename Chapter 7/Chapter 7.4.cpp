#include <iostream>
#include <cstring>

//#define START1
//#define START2
//#define START3
//#define START4
#define START5

using namespace std;


#ifdef START1

//ISAINnheritance.cpp
class Computer
{
	private:
		char owner[50];
		
	public:
		Computer(char* name)
		{
			strcpy(owner, name);
		}
		
		void Calculate()
		{
			cout<<"��û ������ ����մϴ�."<<endl;
		}
};

class NotebookComp : public Computer
{
	private:
		int Battery;
	
	public:
		NotebookComp(char* name, int initChag) : Computer(name), Battery(initChag)
		{
			
		}
		
		void Charging()
		{
			Battery += 5;
		}
		
		void UseBattery()
		{
			Battery -= 1;
		}
		
		void MovingCal()
		{
			if (GetBatteryInfo() < 1)
			{
				cout<<"������ �ʿ��մϴ�."<<endl;
				
				return;
			}
			
			cout<<"�̵��ϸ鼭 ";
			Calculate();
			UseBattery();
		}
		
		int GetBatteryInfo()
		{
			return Battery;
		}
};

class TableNotebook : public NotebookComp
{
	private:
		char regstPenModel[50];
		
	public:
		TableNotebook(char* name, int initChag, char* pen) : NotebookComp(name, initChag)
		{
			strcpy(regstPenModel, pen);
		}
		
		void Write(char* penInfo)
		{
			if(GetBatteryInfo() < 1)
			{
				cout<<"������ �ʿ��մϴ�. "<<endl;
				
				return;
			}
			
			if(strcmp(regstPenModel, penInfo) != 0)
			{
				cout<<"��ϵ� ���� �ƴմϴ�.";
				return;
			}
			
			cout<<"�ʱ� ������ ó���մϴ�."<<endl;
			UseBattery();
		}
		
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TableNotebook tn("������", 5, "ISE-241-242");
	
	nc.MovingCal();
	tn.Write("ISE-241-242");
	
	return 0;
	 
}
#endif /* START1 */ 




#ifdef START2

//HASInheritance.cpp
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

class Police : public Gun
{
	private:
		int handcuffs;
		
	public:
		Police(int bnum, int bcuff) : Gun(bnum),handcuffs(bcuff)
		{
			
		}
		
		void PutHandcuff()
		{
			cout<<"SNAP!"<<endl;
			handcuffs--; 
		}
};

int main(void)
{
	Police pman(5,3);
	pman.Shot();
	pman.PutHandcuff();
	
	return 0;
}
#endif /* START2 */




#ifdef START3

//HASComposite.cpp
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
	return 0;
}
#endif /* START3 */




#ifdef START4

//p312 Question 7-4 NO.1
class Rectangle
{
	private:
		int Hight;
		int Width;
		
	public:
		Rectangle(int h, int w) :Hight(h),Width(w) {}
		
		void ShowAreaInfo()
		{
			cout<<"����: "<<Hight*Width<<endl;
		}
	
};

class Square : public Rectangle
{
	public:
		Square(int side) : Rectangle(side, side) {}
		
};

int main(void)
{
	Rectangle rec(4,3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	
	return 0;
	

}
#endif /* START4 */




#ifdef START5

//p313 Question 7-4 NO.2
class Book
{
	private:
		char *title; //å�� ���� 
		char  *isbn;  //����ǥ�ص�����ȣ 
		 int  price; //å�� ���� 
	
	public:
		Book (char* title, char* isbn, int pri) :price(pri)
		{
			this->title = new char[strlen(title)+1];
			this->isbn = new char[strlen(isbn)+1];
			
			strcpy(this->title, title);
			strcpy(this->isbn, isbn);
			
		}
		void ShowBookInfo()
		{
			cout<<"����: "<<title<<endl;
			cout<<"ISBN: "<<isbn<<endl;
			cout<<"����: "<<price<<endl; 
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
		char* DRMKey; //���Ȱ��� Ű 
		
	public:
		EBook(char* title, char* isbn, int pri, char* DRMKey) :Book(title, isbn, pri)
		{
			this->DRMKey = new char[strlen(DRMKey)+1];
			
			strcpy(this->DRMKey, DRMKey);
		}
		
		void ShowEBookInfo()
		{
			ShowBookInfo();
			cout<<"����Ű: "<<DRMKey<<endl; 
		}
		
		~EBook()
		{
			delete []DRMKey;
		}
};

int main(void)
{
	Book book("���� C++", "555-1234-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	
	EBook ebook("���� C++", "555-1234-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	cout<<endl;
	
	return 0;
	
}

#endif /* START5 */
