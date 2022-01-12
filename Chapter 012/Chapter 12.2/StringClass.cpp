#include "StringClass.h"


String::String()
{
	len = 0;
	str = NULL;
}




String::String(const char* s)
{
    len = strlen(s)+1;
	str = new char[len];
	strcpy(str, s);
} 




String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
} 




String::~String()
{
	if(str != NULL)
	{
		delete []str;
	}	
}




String String::operator+ (const String& s)
{
	char* tempstr = new char[len+s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr); //String temp = tempstr;
	delete []tempstr;
	
	return temp;
	
/*
	strcpy �Լ�
	-> ��� ���ڿ� ��ü�� �����Ѵ�. 
	-> char* strcpy(char* dest, const char* src);
	dest: ���縦 ���� ����� ���� �ּ�
	src : ���縦 �� ������ ���� �ּ�
	
	strcat �Լ�
	-> ���ڿ� A�� ���ϴ� ���ڿ�B�� ���ڿ�A ���ʿ� �̾� ���δ�.
	->char *strcat(char *dest, const char *src);
	dest: ���縦 ���� ����� ���� �ּ�
	src : ���縦 �� ������ ���� �ּ� 
*/	 
}




String& String::operator= (const String& s)
{
	if (str != NULL)
	{
		delete []str;
	}
	
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	
	return *this;	
}




String& String::operator+= (const String& s)
{
	//len += (s.len - 1);
	char* tempstr = new char[len+s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	if (str != NULL)
	{
		delete []str;
	}
	
	str = tempstr; 
	
	return *this;
}




bool String::operator== (const String& s)
{
	return strcmp(str, s.str) ? false : true;

/*
	strcmp �Լ�
	-> �� ���� ���ڿ��� ������ ���Ѵ�. 
	-> ���ڿ��� ������ 0�� ��ȯ (���� ���), ���ڿ��� ���� ������ 0�� �ƴ� ���� ��ȯ (������ ���) 
	->int strcmp(const char* str1, const char* str2);
	dest: ���� ���ڿ�1 
	src : ���� ���ڿ�2 
	 
	���׿����� 
	-> ���� ? ��1: ��2 
	-> ��/������ �Ǵ��� ���� ? ���� �� ����� �� : �����ϋ� ����� �� 
*/
}



	
ostream& operator<<(ostream& os, const String& s)
{
	os<<s.str;
	
	return os;	
}




istream& operator>>(istream& is, String& s)
{
	char str[100];
	is>>str;
	s = String(str);
	
	return is;	
}			
