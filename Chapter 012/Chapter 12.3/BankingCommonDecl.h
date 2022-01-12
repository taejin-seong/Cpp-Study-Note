/*
 * BankingCommonDecl.h
 *
 *  Created on: Jan 12, 2022
 *      Author: Tae Jin
 */


#ifndef BANKING_COMMON_DECL_H 
#define BANKING_COMMON_DECL_H 


#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

//�̸��� ������ �迭ũ��
//const int NAME_LEN = 20;  

//����� �޴� 
enum{
	
	MAKE = 1, 
	DEPOSIT, 
	WITHDRAW,
	INQUIRE,
	EXIT
}; 

//�ſ��� 
enum{
	A = 7,
	B = 4,
	C = 2 
};

//������ ������ ���� 
enum{
	NORMAL = 1,
	CREDIT	
};

#endif /* BANKING_COMMON_DECL_H */
