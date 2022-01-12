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
		String();                                                    //���ڿ��� ���ڷ� ���޹޴� ������ ���� 
		String(const char* s);                                       //���ڿ� ������ ���� �޸� ���� ���� �Ҵ��� ���� ������ ���� 
		String(const String& s);                                     //���� ���縦 �ϴ� ���� ������  
		~String();                                                   //�Ҹ��� 
		String  operator+ (const String& s);                         //���յ� ���ڿ��� �ʱ�ȭ�� ��ü�� ��ȯ�ϴ� + ������ �����ε� 
		String& operator= (const String& s);                         //���� ������ ���� 
		String& operator+= (const String& s);                        //���ڿ��� �����̴� += ������ �����ε� 
		bool operator== (const String& s);                           //����񱳸� �����ϴ� ==������ �����ε� 
		
		friend ostream& operator<<(ostream& os, const String& s);    //�ܼ������ �����ϵ��� << ������ �����ε� 
		friend istream& operator>>(istream& is, String& s);		     //�ܼ��Է��� �����ϵ��� >> ������ �����δ� 		
};

#endif /* STRING_H */
