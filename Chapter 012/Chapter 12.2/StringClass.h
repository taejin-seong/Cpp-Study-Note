/*

string Ŭ������ ��ü�ϴ� String Ŭ������ ����
 
1. ���ڿ��� ���ڷ� ���޹޴� �������� ���� 
2. ������, �Ҹ���, ���� ������ (���� ����) �׸��� ���� �������� ����
3. ���յ� ���ڿ��� �ʱ�ȭ�� ��ü�� ��ȯ�ϴ� + �������� �����ε� 
4. ���ڿ��� �����̴� += �������� �����ε�
5. ����񱳸� �����ϴ� == �������� �����ε�
6. �ܼ�������� �����ϵ��� <<. >> �������� �����ε�

*/ 

#include <iostream>
#include <cstring>


using namespace std;


class String
{
	private:
		int len;
		char* str;
		
	public:
		String();
		String(const char* s);
		String(const String& s);
		~String();
		String  operator+ (const String& s);
		String& operator= (const String& s);
		String& operator+= (const String& s);
		bool operator== (const String& s);
		
		friend ostream& operator<<(ostream& os, const String& s);
		friend istream& operator>>(istream& is, String& s);		
		
} ;
