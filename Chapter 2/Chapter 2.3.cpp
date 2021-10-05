#include <iostream> 

#define START3

using namespace std;


#ifdef START1
/*
1. ������ �Ҵ�� �޸� ������ �ٿ��� �̸�.
2. �����ڴ� �������ٰ� �̸��� �ϳ��� �ٿ��ִ� ����. (�Ҵ�� �޸� ������ �� �̻��� �̸��� �ο��ϴ� ��.)
3. ������ ���� �տ� & -> �ּҰ� ��ȯ
   ������ �����ϴ� ���������� & -> ������ ����
4. �����ڴ� ������ ������ ��ɰ� ������ ����� ���� (������ C++������ �����ڿ� ������ �����ؼ� �̾߱���. )

5. �� �����ڴ� �ڽ��� �����ϴ� ������ ����� �� �ִ� �� �ϳ��� �̸�. 
 
*/

//Referen.cpp
int main(void)
{
	int num1 = 2010;
	int &num2 = num1; // ������ ���� ���. num2�� num1�� ������ 
	// 1. �����ϰ��� �ϴ� ������ ������ �ڷ����� �����Ѵ�.
	// 2. ������ �̸��� �����ϵ� �տ� &�� �ٿ��ش�.
	// 3. num2�� num1�� �����ڰ� �ȴ�. 
	
	num2 = 3047;
	
	cout<<"VAL: "<<num1<<endl;
	cout<<"REF: "<<num2<<endl;
	
	cout<<"VAL: "<<&num1<<endl;
	cout<<"REF: "<<&num2<<endl;
	
	return 0;
	
}

#endif /* START1 */





#ifdef START2
/*
1. �������� ������ ������ ����.
ex)
int num1 = 2579;
int &num2 = num1;
int &num3 = num1;
int &num4 = num1;
int &num5 = num1; ....

2. ������ ������� �����ڸ� �����ϴ� �͵� ����.
ex)
int num1 = 2579;
int &num2 = num1;
int &num3 = num2;
int &num4 = num3;
int &num5 = num4; ....
 
3. �����ڴ� ������ ���ؼ��� ������ ����
ex)
int &ref = 20;  X

4. �̸� �����ڸ� �����ߴٰ�, �Ŀ� �������� �����ϴ� ���� �Ұ���
ex)
int &ref;  X

5. �����ڸ� �����ϸ鼭 NULL�� �ʱ�ȭ�ϴ� �͵� �Ұ���.
ex)
int &ref = NULL;  X 

6. �����ڴ� ������ ����� ���ÿ� ������ �����ϵ��� �ؾ���.
7. ������ �� �ִ� ������ �������� �迭��ҵ� ������ ��. 
*/


//RefArrElem.cpp
int main(void)
{
	int arr[3] = {1,3,5};
	
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout<<ref1<<endl;
	cout<<ref2<<endl;
	cout<<ref3<<endl;
	
	return 0;
	
}

#endif /* START2 */




#ifdef START3
/*
1. �����ͺ����� �����̱� ������ �������� ������ ����. 
*/


//RefPtr.cpp
int main(void)
{
	int num = 12;
	int *ptr = &num;
	int **dpter = &ptr;
	
	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dpter;  // ������ ������ ������ ���� ���. 
	
	cout<<ref<<endl;
	cout<<*pref<<endl;
	cout<<**dpref<<endl;
	
	return 0;
	
}
#endif /* START3 */
