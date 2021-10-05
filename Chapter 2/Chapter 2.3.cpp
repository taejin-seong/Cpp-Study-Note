#include <iostream> 

#define START3

using namespace std;


#ifdef START1
/*
1. 변수는 할당된 메모리 공간에 붙여진 이름.
2. 참조자는 변수에다가 이름을 하나더 붙여주는 개념. (할당된 메모리 공간에 둘 이상의 이름을 부여하는 것.)
3. 기존의 변수 앞에 & -> 주소값 반환
   변수를 선언하는 과정에서의 & -> 참조자 선언
4. 참조자는 참조한 변수의 기능과 연산의 결과가 동일 (하지만 C++에서는 참조자와 변수를 구분해서 이야기함. )

5. 즉 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름. 
 
*/

//Referen.cpp
int main(void)
{
	int num1 = 2010;
	int &num2 = num1; // 참조자 선언 방법. num2는 num1의 참조자 
	// 1. 참조하고자 하는 변수와 동일한 자료형을 선언한다.
	// 2. 참조자 이름을 저장하되 앞에 &를 붙여준다.
	// 3. num2는 num1의 참조자가 된다. 
	
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
1. 참조자의 수에는 제한이 없음.
ex)
int num1 = 2579;
int &num2 = num1;
int &num3 = num1;
int &num4 = num1;
int &num5 = num1; ....

2. 참조를 대상으로 참조자를 선언하는 것도 가능.
ex)
int num1 = 2579;
int &num2 = num1;
int &num3 = num2;
int &num4 = num3;
int &num5 = num4; ....
 
3. 참조자는 변수에 대해서만 선언이 가능
ex)
int &ref = 20;  X

4. 미리 참조자를 선언했다가, 후에 누군가를 참조하는 것은 불가능
ex)
int &ref;  X

5. 참조자를 선언하면서 NULL로 초기화하는 것도 불가능.
ex)
int &ref = NULL;  X 

6. 참조자는 무조건 선언과 동시에 변수를 참조하도록 해야함.
7. 참조할 수 있는 변수의 범위에는 배열요소도 포함이 됨. 
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
1. 포인터변수도 변수이기 때문에 참조자의 선언이 가능. 
*/


//RefPtr.cpp
int main(void)
{
	int num = 12;
	int *ptr = &num;
	int **dpter = &ptr;
	
	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dpter;  // 포인터 변수의 참조자 선언 방법. 
	
	cout<<ref<<endl;
	cout<<*pref<<endl;
	cout<<**dpref<<endl;
	
	return 0;
	
}
#endif /* START3 */
