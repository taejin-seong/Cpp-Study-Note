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
		int AccID;        //계좌번호 
		int Balance;      //잔액
		char* ClientName; //고객이름 
	
	public:
		Account(int id, int moeny, char* name);  //계좌 계설 
		Account(const Account& copy);            //깊은 복사 
		
		int GetID(void) const;                   //ID 반환 
		virtual void Deposit(int money);         //입금 
		int WithDraw(int money);                 //출금 
		void ShowAllAccountInfo(void) const;     //계좌 조회 	
		
		~Account();

};		
	
#endif /* ACCOUNT_H */
