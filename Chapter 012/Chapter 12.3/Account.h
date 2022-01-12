/*
 * Acoount.h
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 */


#ifndef ACOOUNT_H
#define ACOOUNT_H


#include "String.h"


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
