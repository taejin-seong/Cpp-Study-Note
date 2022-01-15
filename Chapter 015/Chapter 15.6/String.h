/*
 * StringCalss.h
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 */


#ifndef STRING_H
#define STRING_H


#include "BankingCommonDecl.h"


class String
{
	private:
		int len;
		char* str;
		
	public:
		String();                                                    //문자열을 인자로 전달받는 생성자 정의 
		String(const char* s);                                       //문자열 저장을 위한 메모리 공간 동적 할당을 위한 생성자 정의 
		String(const String& s);                                     //깊은 복사를 하는 복사 생성자  
		~String();                                                   //소멸자 
		String  operator+ (const String& s);                         //결합된 문자열로 초기화된 객체를 반환하는 + 연산자 오버로딩 
		String& operator= (const String& s);                         //대입 연산자 정의 
		String& operator+= (const String& s);                        //문자열을 덧붙이는 += 연산자 오버로딩 
		bool operator== (const String& s);                           //내용비교를 진행하는 ==연산자 오버로딩 
		
		friend ostream& operator<<(ostream& os, const String& s);    //콘솔출력이 가능하도록 << 연산자 오버로딩 
		friend istream& operator>>(istream& is, String& s);		     //콘솔입력이 가능하도록 >> 연산자 오버로당 		
};

#endif /* STRING_H */
