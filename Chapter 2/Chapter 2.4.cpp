#include <iostream> 

#define START7

using namespace std;


#ifdef START1
/*
1. 함수내에서 함수외부에 선언된 변수를 접근하는 방법 
   1). 주소값을 이용하는 방법 (포인터)
   2). 참조자를 이용하는 방법 
     
2. 매개 변수는 함수가 호출되어야 초기화가 진행되는 변수들이다. 즉, 매개 변수들은 함수가 선언과 동시에 초기화가 이루어지므로 참조자의 기준에 위배되지 않음. 

3. 함수 내의 참조자는 함수가 종료 되면 참조자의 이름은 메모리 공간에서 소멸된다.

4, 참조자의 단점
   1). 직관적이지 못함, 값의 변경이 일어나는지를 확인해야함.
   2). 즉 함수의 정의형태를 봐야함..
   --> const 를 이용하여 어느정도의 단점을 극복
   ex)
   void Func(const int &ref) {...} --> 함수 내에서 참조자 ref를 이용한 값의 변경을 허용하지 않음. ( 값 참조 O / 값 변경 X ) 
*/


void SwapByRef2(int &ref1, int &ref2) // 참조자는 선언과 동시에 변수로 초기화 되어야한다.  
                                      // 실제로 ref1, ref2가 선언되는 시점은 SwapByRef2 함수가 호출되는 시점. 이 함수가 호출될 때 인자로 전달되는 값으로 초기화가 이루어짐. 
                                      // 참조자의 기준에 위배되지 않음. 
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
	
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	                         // 참조자는 변수에 대해서만 선언이 가능. 
	SwapByRef2(val1, val2);  // 10,20이 참조자에 전달되는 것이 아니라 val1, val2라는 이름이 참조하는 메모리 공간에 ref1, ref2라는 이름이 하나 더 생긴 것.
	 
	
	cout<<"val1: "<<val1<<endl;
	cout<<"val2: "<<val2<<endl;

	return 0;	
}

#endif /* START1 */




#ifdef START2
/*
1. 참조형을 반환 했을 때에 "반환형인 참조자"를 참조할 수 있는 참조 값이 반환됨. 

2. 함수 호출 할 때  함수의 매개 변수를 참조자로 받느냐, 변수로 받느냐에 따라 결과가 달라짐.

3. 함수의 매개 변수가 참조자 일 때, 반환형이 참조자인지, 기본 자료형 변수인지에 따라서 결과가 달라짐. 

4. 반환이 참조형일 때 반환된 참조형을 받을 경우  참조로 받느냐, 변수로 저장하느냐에  따라서 결과는 달라짐. 
*/


int& RefRetFuncOne(int &ref) // int& <--- 반환형이 참조자.                    
{
	ref ++;
	
	return ref; // 반환형은 참조자. 
}

int main(void)
{
	int num1 = 1;
	
	int &num2 = RefRetFuncOne(num1); // 반환된 참조형을 참조자로 받음. 
	
	num1 ++;
	num2 ++;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}


// 위 예제에서 보이는 상황...

/* 

int num1 = 1;
int &ref = num1;
int &num2 = ref; ~ 함수 반환 후 참조자 ref 이름은 메모리 공간에서 소멸... 

따라서 num1, num2 모두 같은 메모리 공간을 가지고 있으므로 num1= 3, num2 =3이 됨. 

*/ 

#endif /* START2 */





#ifdef START3
/*
1. 반환이 참조형일 때 참조로 받느냐, 기본자료형으로 받느냐에 따라 결과는 달라짐. 
*/


int& RefRetFuncOne(int &ref) // int& <- 반환형이 참조자. 
{
	ref ++;
	
	return ref;
}

int main(void)
{
	int num1 = 1;
	
	int num2 = RefRetFuncOne(num1); // 반환된 참조형을 기본 자료형 변수로 받음. 
	
	num1 += 1;
	num2 += 100;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}

// 위 예제에서 보이는 상황...

/* 

int num1 = 1;
int &ref = num1;
int num2 = ref; ~ 함수 반환 후 참조자 ref 이름은 메모리 공간에서 소멸...


--> 기본자료형인 num2은 다른 메모리공간이 생김. 
따라서 num1 = 3, num2 =102 라는 결과가 나옴. 

*/ 

#endif /* START3 */





#ifdef START4
/*
1. 반환이 기본자료형일 때 참조자로 받을 수 없음.  
*/


int RefRetFuncOne(int &ref) // int <--- 반환형이 기본자료형 int 이므로 ref에 저장된 값이 반환됨.  
{
	ref ++;
	
	return ref;
}

int main(void)
{
	int num1 = 1;
	
	int num2 = RefRetFuncOne(num1); // 반환형이 int로 제한되었으므로 상수가 반환이 됨. 따라서 참조자로 받을 수 없음. int &num2 = RefRetFuncOne(num1) X 
//                                                                                                                   int num2 = RefRetFuncOne(num1) O  변수에 저장해야함. 
	
	num1 += 1;
	num2 += 100;
	
	cout<< "num1: "<<num1<<endl;
	cout<< "num2: "<<num2<<endl;
	
	return 0;
}


#endif /* START3 */



/*

// 1. 지역변수를 참조의 형태로 반환하는 것은 문제의 소지가 됨.
//    -> ref가 참조하는 대상(지역변수 num) 이 소멸되기 때문에. (함수 호출과정이 끝나면 지역변수는 소멸)

 
int& RetuReFunc(int n)
{
	num =20;
	num += n;
	return num;
}


int &ref = RetuReFunc(10);


*/


/*

// 1. 상수화된 변수에 대한 참조자 선언은 아래와 같음

const int num = 20;
const int &ref = num ;

// 2. const 참조자는 다음과 같이 상수도 참조가 가능함. ( 촘자는 변수만 참조가 가능하다고 했는데.. 
//    리터럴 상수도 메모리 공간에 저장되나 다음행으로 넘어가면 소멸되기 때문에 임시적인 성격을 가진다.
//    const로 리터럴 상수를 참조할 경우에 그 상수는 임시적 성격을 지니지 않도록 특정 메모리공간에 별도로 저장하고 그 저장된 메모리 공간을 참조(ref로 이름을 붙이게)하게 함.
//    따라서 예외적으로 const int &ref로 상수를 참조할 수 있게 허용함.

const int &ref = 50;

*/ 



#ifdef START5

//p80 Question 2-1

//문제1. 참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하여라.
//       -> 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
//       -> 인자로 전달된 int형 변수의 부호를 바꾸는 함수

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

//문제3. ptr1과 ptr2 가리키는 대상이 서로 바뀌도록 SwapPointer 함수를 정의해보자.

int SwapPointer(int *(&ptr1), int *(&ptr2))
{
	int *temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}  

int main(void)
{
	int num1, num2;
	cout<<"2개의 값 입력: ";
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
//문제1. 포인터 변수를 선언해서 위 변수를 가리키게 해보자. 그리고 이 포인터 변수를 참조하는 참조자를 하나 선언하자. 마지막으로 이렇게 선언된 포인터 변수와 참조자를 이용해서
//       num에 저장된 값을 출력하는 예제를 완성해 보자. 


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



























