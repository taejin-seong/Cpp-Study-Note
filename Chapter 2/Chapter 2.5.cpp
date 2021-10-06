#include <iostream>
#include <string.h>
#include <stdlib.h>  // C++���� C����� ��������� �߰��ϴ� �͵� ����. 

#define START4

using namespace std;




#ifdef START1
/*
1. malloc�� free : �Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ��Ѵ�..
                 : �ڷ����� �������� ���� void�� �����Ͱ� ��ȯ��.
				 
2. new�� delete  : C++������ ���� �� ������ �Ҵ��ϰ��� ���� ���� ����߱� ������ ����� ��� �°� ������ ���������� ��ȯ�ȴ�. 
                 : ex)
                   int�� ���� -> int�� �����ͷ� ��ȯ  
*/

//MemMalFree.cpp
char * MakeStrAdr(int len)
{
	char * str = (char*)malloc(sizeof(char)*len);
	return str; 
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	free(str);
	
	return 0;
}

#endif /* START1 */




#ifdef START2
/*
1. new �����ڸ� ����ؼ� ���� �ִ� �޸𸮸� �����Ҵ�
2. delete�� ����ؼ� �Ҵ�� �޸� ������ �Ҹ� 
*/

//NewDelete.cpp
char * MakeStrAdr(int len)
{
	//char * str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len]; // new�� ����Ͽ� �޸𸮸� �����Ҵ�. 
	return str;
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout<<str<<endl;
	//free(str);
	delete []str;  // �Ҹ��ϰ��� �ϴ� ���� �迭�� ���¶�� delete []stró�� []�� �߰��� �迭���� ����ؾ��Ѵ�. 
	
	return 0;
}

#endif /* START2 */




#ifdef START3
/*
1. new�� malloc �Լ��� ���۹�Ŀ��� ���̰� �ִ�.
2. ����� ���� �޸� �Ҵ��̶�� ���鿡���� ���������� �ϴ� �Ͽ� ���Ͽ��� ���̰� �ִ�. 
*/

//NewObject.cpp
class Simple
{
public:
	Simple()
	{
		cout<<"I'm simple constructorl!"<<endl;
	}
};

int main(void)
{
	cout<<"case 1: ";
	Simple * sp1 = new Simple;
	
	cout<<"case 2: ";
	Simple * sp2 = (Simple*)malloc(sizeof(Simple)*1);
	
	cout<<endl<<"end of main"<<endl;
	delete sp1;
	free(sp2);
	
	return 0;
}

#endif /* START2 */




#ifdef START4

//p95 Question 2-3

//����1. å �� �� 

typedef struct __Point
{
	int xpos;
	int ypos;
	
}Point;


Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *pptr = new Point;
	
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p1.ypos;
	
	return *pptr;
}
 
int main(void)
{
	Point *pptr1 = new Point;
	pptr1->xpos = 13;
	pptr1->ypos = 10;
	
	Point *pptr2 = new Point;
	pptr2->xpos = 43;
	pptr2->ypos = 40;
	
	Point &pref = PntAdder(*pptr1, *pptr2);
	cout<<"["<<pref.xpos<<","<<pref.ypos<<"]"<<endl;
	
	delete pptr1;
	delete pptr2;
	delete &pref;
	
	return 0;		
}
 
#endif /* START4 */
 
