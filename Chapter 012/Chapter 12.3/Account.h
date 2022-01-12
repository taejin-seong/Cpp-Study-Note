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
		int AccID;         //계좌번호 
		int Balance;       //잔액 
		String ClientName; //고객이름 
	
	public:
		Account(int id, int moeny, String name);  //계좌 계설 
		int GetID(void) const;                    //ID 반환 
		virtual void Deposit(int money);          //입금 
		int WithDraw(int money);                  //출금 
		void ShowAllAccountInfo(void) const;      //계좌 조회 	

};		
	
#endif /* ACCOUNT_H */
