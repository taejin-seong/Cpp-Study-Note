/*
 * Acoount.h
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 */


#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "String.h"
#include "AccountException.h"


class Account
{
	private:
		int AccID;         //���¹�ȣ 
		int Balance;       //�ܾ� 
		String ClientName; //���̸� 
	
	public:
		Account(int id, int moeny, String name);  //���� �輳 
		int GetID(void) const;                    //ID ��ȯ 
		virtual void Deposit(int money);          //�Ա� 
		int WithDraw(int money);                  //��� 
		void ShowAllAccountInfo(void) const;      //���� ��ȸ 	

};		
	
#endif /* ACCOUNT_H */
