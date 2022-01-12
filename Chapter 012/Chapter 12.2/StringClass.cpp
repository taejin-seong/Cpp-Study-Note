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
	str = s.str;
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
	strcpy 함수
	-> 대상 문자열 전체를 복사한다. 
	-> char* strcpy(char* dest, const char* src);
	dest: 복사를 받을 대상의 시작 주소
	src : 복사를 할 원본의 시작 주소
	
	strcat 함수
	-> 문자열 A에 원하는 문자열B를 문자열A 뒤쪽에 이어 붙인다.
	->char *strcat(char *dest, const char *src);
	dest: 복사를 받을 대상의 시작 주소
	src : 복사를 할 원본의 시작 주소 
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
	strcmp 함수
	-> 두 개의 문자열이 같은지 비교한다. 
	-> 문자열이 같으면 0을 반환 (참인 경우), 문자열이 같지 않으면 0이 아닌 값을 반환 (거짓인 경우) 
	->int strcmp(const char* str1, const char* str2);
	dest: 비교할 문자열1 
	src : 비교할 문자열2 
	 
	삼항연산자 
	-> 변수 ? 값1: 값2 
	-> 참/거짓을 판단할 변수 ? 참일 때 사용할 값 : 거짓일떄 사용할 값 
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
