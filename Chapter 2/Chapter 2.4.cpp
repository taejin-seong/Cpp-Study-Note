#include <iostream> 

#define START7

using namespace std;


#ifdef START1
/*
1. �Լ������� �Լ��ܺο� ����� ������ �����ϴ� ��� 
   1). �ּҰ��� �̿��ϴ� ��� (������)
   2). �����ڸ� �̿��ϴ� ��� 
     
2. �Ű� ������ �Լ��� ȣ��Ǿ�� �ʱ�ȭ�� ����Ǵ� �������̴�. ��, �Ű� �������� �Լ��� ����� ���ÿ� �ʱ�ȭ�� �̷�����Ƿ� �������� ���ؿ� ������� ����. 

3. �Լ� ���� �����ڴ� �Լ��� ���� �Ǹ� �������� �̸��� �޸� �������� �Ҹ�ȴ�.

4, �������� ����
   1). ���������� ����, ���� ������ �Ͼ������ Ȯ���ؾ���.
   2). �� �Լ��� �������¸� ������..
   --> const �� �̿��Ͽ� ��������� ������ �غ�
   ex)
   void Func(const int &ref) {...} --> �Լ� ������ ������ ref�� �̿��� ���� ������ ������� ����. ( �� ���� O / �� ���� X ) 
*/

//RefSwap.cpp
void SwapByRef2(int &ref1, int &ref2) // �����ڴ� ����� ���ÿ� ������ �ʱ�ȭ �Ǿ���Ѵ�.  
                                      // ������ ref1, ref2�� ����Ǵ� ������ SwapByRef2 �Լ��� ȣ��Ǵ� ����. �� �Լ��� ȣ��� �� ���ڷ� ���޵Ǵ� ������ �ʱ�ȭ�� �̷����. 
                                      // �������� ���ؿ� ������� ����. 
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
	
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	                         // �����ڴ� ������ ���ؼ��� ������ ����. 
	SwapByRef2(val1, val2);  // 10,20�� �����ڿ� ���޵Ǵ� ���� �ƴ϶� val1, val2��� �̸��� �����ϴ� �޸� ������ ref1, ref2��� �̸��� �ϳ� �� ���� ��.
	 
	
	cout<<"val1: "<<val1<<endl;
	cout<<"val2: "<<val2<<endl;

	return 0;	
}

#endif /* START1 */




#ifdef START2
/*
1. �������� ��ȯ ���� ���� "��ȯ���� ������"�� ������ �� �ִ� ���� ���� ��ȯ��. 

2. �Լ� ȣ�� �� ��  �Լ��� �Ű� ������ �����ڷ� �޴���, ������ �޴��Ŀ� ���� ����� �޶���.

3. �Լ��� �Ű� ������ ������ �� ��, ��ȯ���� ����������, �⺻ �ڷ��� ���������� ���� ����� �޶���. 

4. ��ȯ�� �������� �� ��ȯ�� �������� ���� ���  ������ �޴���, ������ �����ϴ��Ŀ�  ���� ����� �޶���. 
*/


//RefReturnOne.cpp
int& RefRetFuncOne(int &ref) // int& <--- ��ȯ���� ������.                    
{
	ref ++;
	
	return ref; // ��ȯ���� ������. 
}

int main(void)
{
	int num1 = 1;
	
	int &num2 = RefRetFuncOne(num1); // ��ȯ�� �������� �����ڷ� ����. 
	
	num1 ++;
	num2 ++;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}


// �� �������� ���̴� ��Ȳ...

/* 

int num1 = 1;
int &ref = num1;
int &num2 = ref; ~ �Լ� ��ȯ �� ������ ref �̸��� �޸� �������� �Ҹ�... 

���� num1, num2 ��� ���� �޸� ������ ������ �����Ƿ� num1= 3, num2 =3�� ��. 

*/ 

#endif /* START2 */





#ifdef START3
/*
1. ��ȯ�� �������� �� ������ �޴���, �⺻�ڷ������� �޴��Ŀ� ���� ����� �޶���. 
*/


//RefReturnTwo.cpp
int& RefRetFuncOne(int &ref) // int& <- ��ȯ���� ������. 
{
	ref ++;
	
	return ref;
}

int main(void)
{
	int num1 = 1;
	
	int num2 = RefRetFuncOne(num1); // ��ȯ�� �������� �⺻ �ڷ��� ������ ����. 
	
	num1 += 1;
	num2 += 100;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}

// �� �������� ���̴� ��Ȳ...

/* 

int num1 = 1;
int &ref = num1;
int num2 = ref; ~ �Լ� ��ȯ �� ������ ref �̸��� �޸� �������� �Ҹ�...


--> �⺻�ڷ����� num2�� �ٸ� �޸𸮰����� ����. 
���� num1 = 3, num2 =102 ��� ����� ����. 

*/ 

#endif /* START3 */





#ifdef START4
/*
1. ��ȯ�� �⺻�ڷ����� �� �����ڷ� ���� �� ����.  
*/


//RefReturnThree.cpp
int RefRetFuncOne(int &ref) // int <--- ��ȯ���� �⺻�ڷ��� int �̹Ƿ� ref�� ����� ���� ��ȯ��.  
{
	ref ++;
	
	return ref;
}

int main(void)
{
	int num1 = 1;
	
	int num2 = RefRetFuncOne(num1); // ��ȯ���� int�� ���ѵǾ����Ƿ� ����� ��ȯ�� ��. ���� �����ڷ� ���� �� ����. int &num2 = RefRetFuncOne(num1) X 
//                                                                                                                   int num2 = RefRetFuncOne(num1) O  ������ �����ؾ���. 
	
	num1 += 1;
	num2 += 100;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}


#endif /* START3 */



/*

// 1. ���������� ������ ���·� ��ȯ�ϴ� ���� ������ ������ ��.
//    -> ref�� �����ϴ� ���(�������� num) �� �Ҹ�Ǳ� ������. (�Լ� ȣ������� ������ ���������� �Ҹ�)

 
int& RetuReFunc(int n)
{
	num =20;
	num += n;
	return num;
}


int &ref = RetuReFunc(10);


*/


/*

// 1. ���ȭ�� ������ ���� ������ ������ �Ʒ��� ����

const int num = 20;
const int &ref = num ;

// 2. const �����ڴ� ������ ���� ����� ������ ������. ( ���ڴ� ������ ������ �����ϴٰ� �ߴµ�.. 
//    ���ͷ� ����� �޸� ������ ����ǳ� ���������� �Ѿ�� �Ҹ�Ǳ� ������ �ӽ����� ������ ������.
//    const�� ���ͷ� ����� ������ ��쿡 �� ����� �ӽ��� ������ ������ �ʵ��� Ư�� �޸𸮰����� ������ �����ϰ� �� ����� �޸� ������ ����(ref�� �̸��� ���̰�)�ϰ� ��.
//    ���� ���������� const int &ref�� ����� ������ �� �ְ� �����.

const int &ref = 50;

*/ 



#ifdef START5

//p80 Question 2-1

//����1. �����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����Ͽ���.
//       -> ���ڷ� ���޵� int�� ������ ���� 1�� ������Ű�� �Լ�
//       -> ���ڷ� ���޵� int�� ������ ��ȣ�� �ٲٴ� �Լ�

int IncreaseOne(int &num)
{
	num ++;
}

int InverseSign(int &num)
{
	num *= -1;
}

int main(void)
{
	int val;
	cin>>val;
	
	IncreaseOne(val);
	cout<<val<<endl;
	
	InverseSign(val);
	cout<<val<<endl;
	
	return 0;
}

#endif /* START5 */




#ifdef START6

//p80 Question 2-1

//����3. ptr1�� ptr2 ����Ű�� ����� ���� �ٲ�� SwapPointer �Լ��� �����غ���.

int SwapPointer(int *(&ptr1), int *(&ptr2))
{
	int *temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}  

int main(void)
{
	int num1, num2;
	cout<<"2���� �� �Է�: ";
	cin>>num1>>num2;
	
	int *ptr1= &num1;
	int *ptr2= &num2;
	
	SwapPointer(ptr1, ptr2);
	
	cout<<*ptr1<<' '<<*ptr2<<endl;
	
	
	return 0;
	
}

#endif /* START6 */




#ifdef START7

//p90 Question 2-2

                     // const int num = 12; 
//����1. ������ ������ �����ؼ� �� ������ ����Ű�� �غ���. �׸��� �� ������ ������ �����ϴ� �����ڸ� �ϳ� ��������. ���������� �̷��� ����� ������ ������ �����ڸ� �̿��ؼ�
//       num�� ����� ���� ����ϴ� ������ �ϼ��� ����. 


int main(void)
{
	const int num = 12;
	const int *ptr = &num;
	const int *(&ref) = ptr;
	
	cout<<*ptr<<endl;
	cout<<*ref<<endl;
	
	return 0;
}

#endif /* START7 */

