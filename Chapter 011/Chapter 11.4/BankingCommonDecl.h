/*
 * BankingCommonDecl.h
 *
 *  Created on: Jan 6, 2022
 *      Author: Tae Jin
 */


#ifndef BANKING_COMMON_DECL_H 
#define BANKING_COMMON_DECL_H 


#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

//이름을 저장할 배열크기
const int NAME_LEN = 20;  

//사용자 메뉴 
enum{
	
	MAKE = 1, 
	DEPOSIT, 
	WITHDRAW,
	INQUIRE,
	EXIT
}; 

//신용등급 
enum{
	A = 7,
	B = 4,
	C = 2 
};

//생성할 계좌의 종류 
enum{
	NORMAL = 1,
	CREDIT	
};

#endif /* BANKING_COMMON_DECL_H */
