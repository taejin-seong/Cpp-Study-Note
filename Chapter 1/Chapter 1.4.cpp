#include <iostream> 
#define START1



#ifdef START1
/*
1. 인라인 함수는 매크로 함수 처럼 함수의 호출로 인한 스택의 할당과 반환이라는 과정을 생략할 수 있음 -> 성능 향상, 매크로 함수 장점 
2. 인라인 함수는 복잡한 함수들도 인라인 함수들로 정희 가능함 -> 매크로 함수 단점 보안
3. 매크로 함수는"전처리기"에 의해서 처리된다. (컴파일 이전에 처리 됨),
4. 매크로 함수와 동일한 기능을 하는 인라인 함수는 "컴파일러"가 처리함. -> 인라인화가 오히려 성능에 해가 된다고 판단할 경우, 무시해버리기도 한다. 
5. 매크로 함수는 자료형에 독립적이나.. 인라인 함수는 자료형에 의존적. 
*/

//InlineFunc.cpp
inline int SQUARE(int x)  // 인라인 함수의 정의방법, 키워드 inline의 선언을 통해서 함수 SQUARE는 인라인 함수가 되었음. 
{
	return x*x;
}

int main(void)
{
	std::cout<<SQUARE(5)<<std::endl;  // 인라인 함수인 SQUARE 함수 호출  
	std::cout<<SQUARE(12)<<std::endl;
	
	return 0;
}

#endif /* START1 */
