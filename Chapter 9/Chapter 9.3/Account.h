/*
 * Acoount.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef ACOOUNT_H
#define ACOOUNT_H


#include "BankingCommonDecl.h"


class Account
{
	private:
		int AccID;        //���¹�ȣ 
		int Balance;      //�ܾ�
		char* ClientName; //���̸� 
	
	public:
		Account(int id, int moeny, char* name);  //���� �輳 
		Account(const Account& copy);            //���� ���� 
		
		int GetID(void) const;                   //ID ��ȯ 
		virtual void Deposit(int money);         //�Ա� 
		int WithDraw(int money);                 //��� 
		void ShowAllAccountInfo(void) const;     //���� ��ȸ 	
		
		~Account();

};		
	
#endif /* ACCOUNT_H */
